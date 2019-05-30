#include <cstdio>
#include <cryptopp/elgamal.h>
#include <cryptopp/files.h>
//#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>

// gcc -Wall main.cpp -lcryptopp -lstdc++

using namespace std;
using namespace CryptoPP;


int main(int argc, char** argv) {
    AutoSeededRandomPool rng;
    ElGamalKeys::PrivateKey priv;
    priv.GenerateRandomWithKeySize(rng, 2048);
    
    ElGamal::Decryptor decryptor(priv);
    decryptor.AccessKey().Save(FileSink("priv.der", true).Ref());
    return 0;
}