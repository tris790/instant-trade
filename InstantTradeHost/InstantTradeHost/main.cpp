#include <iostream>
#include "httplib.h"

int main(void) {
	httplib::Server svr;

	svr.Get("/whisper", [](const auto&, auto& res) {
		res.set_content("Hello World!", "text/plain");
		std::cout << "Received a packet" << std::endl;
		});

	std::cout << "start server..." << std::endl;
	svr.listen("0.0.0.0", 8080);
}