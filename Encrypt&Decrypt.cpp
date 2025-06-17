#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the message
string encrypt(string text, int key) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = ch + key;
            if (ch > 'Z') {  
                ch = ch - 26;
            }
        } else if (islower(ch)) {
            ch = ch + key;
            if (ch > 'z') { 
                ch = ch - 26;
            }
        }
        encrypted = encrypted + ch;
    }
    return encrypted;
}

// Function to decrypt the message
string decrypt(string text, int key) {
    string decrypted = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = ch - key;
            if (ch < 'A') { 
                ch = ch + 26;
            }
        } else if (islower(ch)) {
            ch = ch - key;
            if (ch < 'a') {  
                ch = ch + 26;
            }
        }
        decrypted = decrypted + ch;
    }
    return decrypted;
}

int main() {
    string message;
    int key = 3; 
    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    string EMessage = encrypt(message, key);
    cout << "Encrypted Message: " << EMessage << endl;

    string DMessage = decrypt(EMessage, key);
    cout << "Decrypted Message: " << DMessage << endl;

    return 0;
}
