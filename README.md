say
===

A simple, cross-platform, text to speech package for Haskell.

Dependencies
------------

###Windows and Mac OSX

No external dependencies.

###Linux

* libspeechd - `sudo apt-get install libspeechd-dev` on Ubuntu/Debian

Compiling Dependant Exectutables on Windows
-------------------------------------------

Due to the way that Cabal links ([or doesn't link](http://stackoverflow.com/questions/17437164/static-lib-required-for-compiling-library-is-also-required-for-library-users)), the files `TTSWinWrapper.lib` and `TTSWinWrapper.dll` must be available to Cabal when building any package which sepends on `say`. The easist way to do this is to place them in the working directory (and possibly use the `ld-options: -L.` .cabal field.

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
