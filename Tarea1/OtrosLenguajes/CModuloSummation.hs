module Main where

main :: IO ()
main = do
    input <- getContents
    let allLines = lines input
    
    case allLines of
        (firstLine:numLine:_) -> do
            let n = read firstLine :: Int
            let numeros = map read (words numLine) :: [Int]
            let total = sum numeros - n
            print total
        _ -> return ()