#include "httplib.h"

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello, World from C++ with httplib!", "text/plain");
    });

    svr.Get("/about", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("This is the about page", "text/plain");
    });

    // Слушаем все IP-адреса на порту 80
    svr.listen("0.0.0.0", 80);
    return 0;
}
