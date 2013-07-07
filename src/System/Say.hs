module System.Say (say, setVolume) where

import Control.Monad
import Foreign.C
import Foreign.C.String
import System.Say.FFI

-- | Send a string to the TTS system.
say :: String -> IO ()
say = csay <=< newCString

-- | Set the current volume of the TTS system.
setVolume :: Int -- ^ Value between 0 and 100
          -> IO ()
setVolume = csetVolume . toEnum
