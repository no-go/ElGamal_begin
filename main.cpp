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
    ElGamalKeys::PublicKey publ;
    
    FileSource publInput("publ.der", true);
    publ.Load(publInput);
        
    ElGamal::Encryptor encryptor(publ);
    string plain = argv[1];
    
    SecByteBlock plaintext((const byte*) plain.data(), plain.size());
    
    size_t ecleng = encryptor.CiphertextLength(plaintext.size());
    SecByteBlock ciphertext(ecleng);
    
    encryptor.Encrypt(rng, plaintext, plaintext.size(), ciphertext);
    
    string cipher((const char*)ciphertext.data(), ciphertext.size());
    printf("%s\n", cipher.c_str());
    
    // ----------------------------------
    
    ElGamalKeys::PrivateKey priv;
    
    FileSource privInput("priv.der", true);
    priv.Load(privInput);
    ElGamal::Decryptor decryptor(priv);
    
    size_t decleng = decryptor.MaxPlaintextLength(cipher.size());
    SecByteBlock recovered(decleng);
    
    SecByteBlock strangeMsg((const byte*)cipher.data(), cipher.size());
    decryptor.Decrypt(rng, strangeMsg, strangeMsg.size(), recovered);

    string plain2((const char*)recovered.data(), recovered.size());
    printf("%s\n", plain2.c_str());
    
    return 0;
}