--initial conditions: one True cell approximately in the middle
start :: Integer -> [Bool]
start n = [if( i == (floor ((fromInteger n) /2))) then True else False | i <- [1..n]] 

--rule30 definition
rule :: (Bool,Bool,Bool) -> Bool 
rule (True,True,True) = False
rule (True,True,False) = False
rule (True,False,True) = False
rule (True,False,False) = True
rule (False,True,True) = True
rule (False,True,False) = True
rule (False,False,True) = True
rule (False,False,False) = False

--gets neighborhood to do rule30
nei :: [Bool] -> Int -> (Bool,Bool,Bool)
nei x i = (x !! ((i-1) `mod` length x), x !! (i `mod` length x), x !! ((i+1) `mod` length x))

--does cellular automation
automata :: [Bool] -> [Bool]
automata x = [(rule(nei (x) i)) | i <- [0..length x-1]]

--fancy output stuff
boolToChar :: Bool -> Char
boolToChar True = '$'
boolToChar False = '.'

output :: [[Bool]] -> Int -> IO ()
output u n  = do 
        putStr (concat [(map boolToChar(u !! i)) ++ "\n" | i <- [0,1..n]])

main = do
        let x = start 200
        let u = iterate automata x 
        output u 1000

