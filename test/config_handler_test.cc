#include "../src/config_handler.h"
#include "config_parser_mock.h"
#include <string>

class ConfigHandlerTest: public::testing::Test
{
protected:
	bool HandleConfig(bool config_parser_return, NginxConfigStatement *statement) {
		config_handler  = new ConfigHandler(mock_config_parser);
		config_handler->config.statements_.emplace_back(statement);
		EXPECT_CALL(mock_config_parser, Parse(config_file_path, &config_handler->config))\
		    .Times(::testing::Exactly(1))\
		    .WillOnce(::testing::Return(config_parser_return));
		return config_handler->handle_config(config_file_path);
	}

    NginxConfigParserMock mock_config_parser;
    ConfigHandler *config_handler = nullptr;
    const char* config_file_path = ".";
};

TEST_F(ConfigHandlerTest, ParseFail) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("port");
	statement->tokens_.push_back("8080");
	EXPECT_FALSE(HandleConfig(false, statement));
}

TEST_F(ConfigHandlerTest, TokenPort) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("port");
	statement->tokens_.push_back("8080");
	EXPECT_TRUE(HandleConfig(true, statement));

	statement->tokens_.push_back("nothing");
	EXPECT_FALSE(HandleConfig(true, statement));
}

TEST_F(ConfigHandlerTest, TooLargePortNumber) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("listen");
	statement->tokens_.push_back("65537");
	EXPECT_FALSE(HandleConfig(true, statement));
}

TEST_F(ConfigHandlerTest, InvalidPortNumber) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("listen");
	statement->tokens_.push_back("hgfer");
	EXPECT_FALSE(HandleConfig(true, statement));
}

/*TEST_F(ConfigHandlerTest, EchoHandlerMap) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("handler_map");
	statement->tokens_.push_back("echo_handler");
	statement->tokens_.push_back("/echo");
	EXPECT_TRUE(HandleConfig(true, statement));
	EXPECT_EQ(config_handler->get_config_opt().echo_paths, std::vector<std::string>{"/echo"});
	EXPECT_EQ(config_handler->get_config_opt().echo_paths.size(), 1);
	EXPECT_EQ(config_handler->get_config_opt().static_paths.size(), 0);
}

TEST_F(ConfigHandlerTest, StaticHandlerMap) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("handler_map");
	statement->tokens_.push_back("static_handler");
	statement->tokens_.push_back("/static1");
	statement->tokens_.push_back("/static2");
	EXPECT_TRUE(HandleConfig(true, statement));

	std::vector<std::string> real_static_paths = {"/static1", "/static2"};
	EXPECT_EQ(config_handler->get_config_opt().static_paths, real_static_paths);
	EXPECT_EQ(config_handler->get_config_opt().static_paths.size(), 2);
	EXPECT_EQ(config_handler->get_config_opt().echo_paths.size(), 0);
}

TEST_F(ConfigHandlerTest, ServerToken) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("server");
	EXPECT_FALSE(HandleConfig(true, statement));

	NginxConfig* child_config = new NginxConfig;
	child_config->statements_.emplace_back(new NginxConfigStatement);
	child_config->statements_.back().get()->tokens_.push_back("listen");
	child_config->statements_.back().get()->tokens_.push_back("1080");
	statement->child_block_.reset(child_config);

	EXPECT_TRUE(HandleConfig(true, statement));
}

TEST_F(ConfigHandlerTest, FormatForBasePath) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("base_path");
	EXPECT_FALSE(HandleConfig(true, statement));

	statement->tokens_.push_back("/static");
	statement->tokens_.push_back("foo/bar");
	EXPECT_TRUE(HandleConfig(true, statement));	
}

TEST_F(ConfigHandlerTest, BasePathMap) {
	NginxConfigStatement *statement = new NginxConfigStatement;
	statement->tokens_.push_back("base_path");
	statement->tokens_.push_back("/static");
	statement->tokens_.push_back("foo/bar");
	EXPECT_TRUE(HandleConfig(true, statement));
	
	std::map<std::string, std::string> real_base_path = {{"/static", "foo/bar"}};
	EXPECT_EQ(config_handler->get_config_opt().url_root2base_dir, 
			  real_base_path);
	EXPECT_EQ(config_handler->get_config_opt().url_root2base_dir.size(), 1);
}*/







