#include <cstdio>
#include <cryptopp/elgamal.h>
#include <cryptopp/files.h>
//#include <cryptopp/cryptlib.h>
#include <cryptopp/osrng.h>

// gcc -Wall main.cpp -lcryptopp -lstdc++

using namespace std;
using namespace CryptoPP;


int main(int argc, char** argv) {
    ElGamalKeys::PrivateKey priv;
    FileSource input("priv.der", true);
    priv.Load(input);
    
    ElGamal::Decryptor decryptor(priv);
    ElGamal::Encryptor encryptor(decryptor);
    ElGamalKeys::PublicKey publ = encryptor.AccessKey();
    
    publ.Save(FileSink("publ.der", true).Ref());
    return 0;
}