#include <cctype>
#include <cstddef>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <string>
#include <vector>

typedef unsigned char byte;

class CryptographyStrategy{
    public:
        virtual std::string encrypt(const std::string&, 
                                    const std::vector<byte>& key = {},
                                    const std::vector<byte>& iv = {}) = 0;
        virtual std::string decrypt(const std::string&, 
                                    const std::vector<byte>& key = {},
                                    const std::vector<byte>& iv = {}) = 0;
        void handleErrors(void){
            ERR_print_errors_fp(stderr);
            abort();
        }
};

class CeasarCipherStrategy : public CryptographyStrategy {
    public:
    std::string encrypt(const std::string& message, 
                        const std::vector<byte>& key,
                        const std::vector<byte>& iv){
        std::string enc_str = "";
        for(const char& c : message){
            if(std::isalpha(c)){
                char temp_c = (c + 3) % 26;
                enc_str += temp_c;
            }
            else{
                enc_str += c;
            }
        }
        return enc_str;
    }

    std::string decrypt(const std::string& message, 
                        const std::vector<byte>& key,
                        const std::vector<byte>& iv){
        std::string dec_str = "";
        for(const char& c : message){
            if(std::isalpha(c)){
                char temp_c = (c - 3) % 26;
                dec_str += temp_c;
            }
            else{
                dec_str += c;
            }
        }
        return dec_str;
    }
};

class AESCipherStrategy : public CryptographyStrategy {
    public:
        std::string encrypt(const std::string& message, 
                            const std::vector<byte>& key,
                            const std::vector<byte>& iv){
            EVP_CIPHER_CTX *ctx;
            int len = message.length();

            if(!(ctx = EVP_CIPHER_CTX_new())){
                handleErrors();
            }
            
            if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data())){
                handleErrors();
            }

            byte* ciphertext = new byte[len + AES_BLOCK_SIZE];
            int ciphertext_len;

            if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, reinterpret_cast<const byte*>(message.c_str()), len)){
                handleErrors();
            };

            if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len)){
                handleErrors();
            }
            std::string enc_str(reinterpret_cast<char*>(ciphertext), ciphertext_len);
            EVP_CIPHER_CTX_free(ctx);
            delete[] ciphertext;
            return enc_str;
        }

        std::string decrypt(const std::string& message, 
                            const std::vector<byte>& key,
                            const std::vector<byte>& iv){
            EVP_CIPHER_CTX *ctx;
            int len = message.length();

            if(!(ctx = EVP_CIPHER_CTX_new())){
                handleErrors();
            }

            if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data())){
                handleErrors();
            }

            byte* plaintext = new byte[len + AES_BLOCK_SIZE];
            int plaintext_len;

            if(1 != EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, reinterpret_cast<const byte*>(message.c_str()), len)){
                handleErrors();
            }

            if(1 != EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len)){
                handleErrors();
            }

            std::string dec_str(reinterpret_cast<char*>(plaintext), plaintext_len);
            EVP_CIPHER_CTX_free(ctx);
            delete[] plaintext;
            return dec_str;
        }

};

class DESCipherStrategy : public CryptographyStrategy {
    public:
        std::string encrypt(const std::string& message, 
                            const std::vector<byte>& key,
                            const std::vector<byte>& iv){
            EVP_CIPHER_CTX *ctx;
            int len = message.length();

            if(!(ctx = EVP_CIPHER_CTX_new())){
                handleErrors();
            }
            
            if(1 != EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key.data(), iv.data())){
                handleErrors();
            }

            byte* ciphertext = new byte[len + AES_BLOCK_SIZE];
            int ciphertext_len;

            if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, reinterpret_cast<const byte*>(message.c_str()), len)){
                handleErrors();
            };

            if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len)){
                handleErrors();
            }
            std::string enc_str(reinterpret_cast<char*>(ciphertext), ciphertext_len);
            EVP_CIPHER_CTX_free(ctx);
            delete[] ciphertext;
            return enc_str;
        }

        std::string decrypt(const std::string& message, 
                            const std::vector<byte>& key,
                            const std::vector<byte>& iv){
            EVP_CIPHER_CTX *ctx;
            int len = message.length();

            if(!(ctx = EVP_CIPHER_CTX_new())){
                handleErrors();
            }

            if(1 != EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key.data(), iv.data())){
                handleErrors();
            }

            byte* plaintext = new byte[len + AES_BLOCK_SIZE];
            int plaintext_len;

            if(1 != EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, reinterpret_cast<const byte*>(message.c_str()), len)){
                handleErrors();
            }

            if(1 != EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len)){
                handleErrors();
            }

            std::string dec_str(reinterpret_cast<char*>(plaintext), plaintext_len);
            EVP_CIPHER_CTX_free(ctx);
            delete[] plaintext;
            return dec_str;
        }

};

class TextEncryptionTool{
    private:
        std::unique_ptr<CryptographyStrategy> strategy;
        std::vector<byte> key;
        std::vector<byte> iv;
    public:
        explicit TextEncryptionTool(std::unique_ptr<CryptographyStrategy> strategy) :
            strategy(std::move(strategy)){}
        
        void setStrategy(std::unique_ptr<CryptographyStrategy> strategy){
            this->strategy = std::move(strategy);
        }

        std::string encrypt(const std::string& message, 
                            const std::vector<byte>& key = {},
                            const std::vector<byte>& iv = {}){
            return strategy->encrypt(message, key, iv);
        }

        std::string decrypt(const std::string& message, 
                            const std::vector<byte>& key = {},
                            const std::vector<byte>& iv = {}){
            return strategy->decrypt(message, key, iv);
        }
        void setKey(const int keySize){
            key.resize(keySize);
            RAND_bytes(key.data(), keySize);
        }

        std::vector<byte> getKey(){
            return key;
        }

        void setIv(const int ivSize){
            iv.resize(ivSize);
            RAND_bytes(iv.data(), ivSize);
        }

        std::vector<byte> getIv(){
            return iv;
        }
};

class Notepad : public TextEncryptionTool {

    public:
        explicit Notepad(std::unique_ptr<CryptographyStrategy> strategy) :
            TextEncryptionTool(std::move(strategy)){}
};

class MSWord : public TextEncryptionTool {

    public:
        explicit MSWord(std::unique_ptr<CryptographyStrategy> strategy) :
            TextEncryptionTool(std::move(strategy)){}
};

int main(){
    Notepad notePad(std::make_unique<CeasarCipherStrategy>());
    std::string ceasar_str = notePad.encrypt("Hello Manoj!");
    std::cout << "Encrypting 'Hello Manoj! with Ceasar Cipher: " << ceasar_str << std::endl;
    std::cout << "Decrypting 'Hello Manoj!' with Ceasar Cipher: " << notePad.decrypt(ceasar_str) << std::endl;

    MSWord msWord(std::make_unique<AESCipherStrategy>());
    msWord.setKey(256);
    msWord.setIv(128);
    std::string aes_str = msWord.encrypt("Hello Manoj!", msWord.getKey(), msWord.getIv());
    std::cout << "Encrypting 'Hello Manoj! with AES 256': " << aes_str << std::endl;
    std::cout << "Decrypting 'Hello Manoj! with AES 256': " << msWord.decrypt(aes_str, msWord.getKey(), msWord.getIv()) << std::endl;

}
