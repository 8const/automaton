import Data.Bits
import System.Environment   




--initial conditions: one True cell approximately in the middle
start :: Integer -> [Bool]
start n = [if( i == (floor ((fromInteger n) /2))) then True else False | i <- [1..n]] 

intToBool :: Int -> Bool
intToBool 0 = False 
intToBool _ = True 


--rule definition
rule :: Int -> (Bool,Bool,Bool) -> Bool 
rule n (True,True,True)    = if intToBool ((.&.) n 128) then True else False 
rule n (True,True,False)   = if intToBool ((.&.) n 64)  then True else False 
rule n (True,False,True)   = if intToBool ((.&.) n 32)  then True else False 
rule n (True,False,False)  = if intToBool ((.&.) n 16)  then True else False 
rule n (False,True,True)   = if intToBool ((.&.) n 8)   then True else False 
rule n (False,True,False)  = if intToBool ((.&.) n 4)   then True else False 
rule n (False,False,True)  = if intToBool ((.&.) n 2)   then True else False 
rule n (False,False,False) = if intToBool ((.&.) n 1)   then True else False 

--gets neighborhood to do rule30
nei :: [Bool] -> Int -> (Bool,Bool,Bool)
nei x i = (x !! ((i-1) `mod` length x), x !! (i `mod` length x), x !! ((i+1) `mod` length x))

--does cellular automation
--its input needs Int n for rule number, but "iterate" only works with endomorphisms
--so I had to make its output also contain Int n
--probably a very stupid solution, but it works
--I hate it
automata :: ([Bool],Int) -> ([Bool],Int)
automata (x, n) = ([(rule n (nei x i)) | i <- [0..length x-1]],n)

--fancy output stuff
boolToChar :: Bool -> Char
boolToChar True = '$'
boolToChar False = '.'

output :: ([([Bool], Int)], Int) -> IO ()
output (u, n)   = do 
        putStr (concat [(map boolToChar(fst (u !! i))) ++ "\n" | i <- [0,1..n]])

main = do
        args <- getArgs
        let r = read(args !! 0)
        let m = read(args !! 1)
        let n = read(args !! 2)


        let x = start n 
        let u = iterate automata (x,r) 
        output (u, m)

