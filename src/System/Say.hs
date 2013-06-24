module System.Say (say, setVolume, withVolume) where

import Control.Monad
import Foreign.C
import Foreign.C.String
import System.Say.FFI

say :: String -> IO ()
say = csay <=< newCString

setVolume :: Int -> IO ()
setVolume = csetVolume . toEnum

withVolume :: Int -> IO a -> IO a
withVolume = undefined
