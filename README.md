# ElGamal_begin

Generate private and public key as files and use them for encrypt and decrypt with crypto++.

## create private key file

    gcc -Wall privCreateAndSave.cpp -o create_priv -lcryptopp -lstdc++
    ./create_priv
    
This take a while!

## create public key file

    gcc -Wall privReadAndSavePub.cpp -o create_pub -lcryptopp -lstdc++
    ./create_pub
    
This reads the `priv.der` private key file and generates a public key file.


## read public key to encode argv

    gcc -Wall main.cpp -o use_me -lcryptopp -lstdc++
    ./use_me "Hallo Bob."

File `main.cpp` also read private key to decode the result.

## your turn

use this base code to make base64 stuff and tcpsockets as a point-to-point encryption(?)