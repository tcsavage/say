{-# LANGUAGE ForeignFunctionInterface #-}

module System.Say (say, setVolume, withVolume) where

import Control.Monad
import Foreign.C
import Foreign.C.String

foreign import ccall safe "cTTS.h csay"
    csay :: CString  -> IO ()

say :: String -> IO ()
say = csay <=< newCString

foreign import ccall safe "cTTS.h csetVolume"
    csetVolume :: CInt -> IO ()

setVolume :: Int -> IO ()
setVolume = undefined

withVolume :: Int -> IO a -> IO a
withVolume = undefined
