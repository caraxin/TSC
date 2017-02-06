#include "../src/echo_request_handler.h"
#include <string>
#include "gtest/gtest.h"



//unit test for check_serve_path function in class echo_request_handler 
class EchoRequestHandlerTest : public::testing::Test
{
protected:
	std::vector<std::string> echo_path;
	http::server::EchoRequestHandler* echoHandler;

	EchoRequestHandlerTest()
	{
		echo_path.push_back("/echo1");
		echo_path.push_back("/echo2");
		echoHandler = new http::server::EchoRequestHandler(echo_path);
	}

	~EchoRequestHandlerTest()
	{
		if(echoHandler != NULL)delete echoHandler;
	}
};

TEST_F(EchoRequestHandlerTest, ValidEchoPath)
{
	EXPECT_TRUE(echoHandler->check_serve_path("/echo1"));
	EXPECT_TRUE(echoHandler->check_serve_path("/echo2"));
}

TEST_F(EchoRequestHandlerTest,InvalidEchoPath)
{
	EXPECT_FALSE(echoHandler->check_serve_path("/static1"));
	EXPECT_FALSE(echoHandler->check_serve_path("/static2"));
	EXPECT_FALSE(echoHandler->check_serve_path("/static1/echo1/content.html"));
}


