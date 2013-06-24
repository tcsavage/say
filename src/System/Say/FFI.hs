{-# LANGUAGE ForeignFunctionInterface #-}

module System.Say.FFI (csay, csetVolume) where

import Foreign.C
import Foreign.C.String

foreign import ccall safe "cTTS.h csay"
    csay :: CString  -> IO ()

foreign import ccall safe "cTTS.h csetVolume"
    csetVolume :: CInt -> IO ()
