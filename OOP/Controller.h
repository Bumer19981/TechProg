#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CipherTextClass
{
private:
	string openText;
	string cipherText;
public:
	virtual void ReadCipherFromFile(ifstream& in);
	virtual void WriteCipherToFile(ofstream& out);
	string GetOpenText();
	void SetOpenText(string value);

	string GetCipherText();
	void SetCipherText(string value);

	virtual void GlobalMM( CipherTextClass* other, ofstream& out );

	virtual void ShiftMM( ofstream& out );
	virtual void RepToCharMM( ofstream& out );
};

class ShiftEncryptionClass : public CipherTextClass
{
private:
	int _shift;
public:
	int GetShift();
	void SetShift(int value);

	void ReadCipherFromFile(ifstream& in) override;
	void WriteCipherToFile(ofstream& out) override;

	void GlobalMM( CipherTextClass* other, ofstream& out ) override;

	void ShiftMM( ofstream& out ) override;
	void RepToCharMM( ofstream& out ) override;
};

struct KeyPair
{
	char openChar;
	char cipherChar;
};

class ReplacementToCharEcnryptionClass : public CipherTextClass
{
private:
	vector <KeyPair> _pairs;
public:
	vector<KeyPair> GetPairs();
	void SetPairs(vector<KeyPair> value);
	void ReadCipherFromFile(ifstream& in) override;
	void WriteCipherToFile(ofstream& out) override;

	void GlobalMM( CipherTextClass* other, ofstream& out ) override;

	void ShiftMM( ofstream& out ) override;
	void RepToCharMM( ofstream& out ) override;
};


class HashArray
{
private:
	int getHash(CipherTextClass* cipher);
public:
	vector<CipherTextClass*>* Conteiner;

	const int MAXHASH = 128;
	bool ReadFile(ifstream& in);
	bool WriteFile(ofstream& out);

	void GlobalMM( ofstream& out );

	HashArray();
	~HashArray();
};
