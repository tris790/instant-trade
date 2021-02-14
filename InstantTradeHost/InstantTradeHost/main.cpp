#include <iostream>
#include "httplib.h"

int main(void) {
	httplib::Server svr;

	svr.Get("/whisper", [](const auto& req, auto& res) {
		std::cout << "Received a packet " << req.body << std::endl;
		res.set_content("ACK", "text/plain");
	});

	std::cout << "start server..." << std::endl;
	svr.listen("0.0.0.0", 8080);
}