module Main where

import Control.Monad
import System.Say

main :: IO ()
main = putStrLn "Type words and hit return to hear them back." >> (forever $ say =<< getLine)
