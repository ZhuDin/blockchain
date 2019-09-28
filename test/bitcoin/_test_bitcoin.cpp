#include <interfaces/node.h>
#include <util/system.h>

#include <key.h>
#include <key_io.h>

#include <pubkey.h>

#include <string>
#include <vector>

static const std::string strSecret1 = "5HxWvvfubhXpYYpS3tJkw6fq9jE9j18THftkZjHHfmFiWtmAbrj";
static const std::string strSecret2 = "5KC4ejrDjv152FGwP386VD1i2NYc5KkfSMyv1nGy1VGDxGHqVY3";
static const std::string strSecret1C = "Kwr371tjA9u2rFSMZjTNun2PXXP3WPZu2afRHTcta6KxEUdm1vEw";
static const std::string strSecret2C = "L3Hq7a8FEQwJkW1M2GNKDW28546Vp5miewcCzSqUD9kCAXrJdS3g";
static const std::string addr1 = "1QFqqMUD55ZV3PJEJZtaKCsQmjLT6JkjvJ";
static const std::string addr2 = "1F5y5E5FMc5YzdJtB9hLaUe43GDxEKXENJ";
static const std::string addr1C = "1NoJrossxPBKfCHuJXT4HadJrXRE9Fxiqs";
static const std::string addr2C = "1CRj2HyM1CXWzHAXLQtiGLyggNT9WQqsDs";

static const std::string strAddressBad = "1HV9Lc3sNHZxwj4Zk6fB38tEmBryq2cBiF";

int main()
{
// #0 node run
	printf("run _test_bitcoin.cpp ...\n");	printf("\tsystem.h define : extern ArgsManager gArgs\n");
	std::string network = gArgs.GetChainName();
	SelectParams(network);
	// MakeNode();
	printf("\n");

	printf("test key ...\n");
	std::string strSecret = strSecret1;
	CKey key1 = DecodeSecret(strSecret);
	printf("\n");

	printf("GetPubKey of DecodeSecret(strSecret) ...\n");
	printf("\tNow the strSecret Valid ? %d\n", key1.IsValid());
	printf("\tNow the strSecret UnCompressed ? %d\n", !key1.IsCompressed());
	CPubKey pubkey1  = key1. GetPubKey();

// test

	return 0;
}