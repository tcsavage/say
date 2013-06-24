say
===

A simple, cross-platform, text to speech package for Haskell.

Dependencies
------------

###Windows and Mac OSX

No external dependencies.

###Linux

* libspeechd - `sudo apt-get install libspeechd-dev` on Ubuntu/Debian

Example Usage
-------------

```haskell
import System.Say

-- say :: String -> IO ()

main :: IO ()
main = do
    words <- getLine
    say words
```
