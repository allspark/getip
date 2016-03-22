/* getip: A small fastcgi handler that returns the client's IP address.
 * Author: Lukas Martini <lutoma@ohai.su>
 * Author: Moritz Kaspar Rudert (mortzu) <me@mortzu.de>
 * Author: Dennis Börm <allspark@wormhole.eu>
 *
 * To the extent possible under law, Lukas Martini has waived all copyright and
 * related or neighboring rights to getip. This work is published from: United
 * States.
 *
 * For more information and the legal code, see
 * http://creativecommons.org/publicdomain/zero/1.0/legalcode
 */

#include <iostream>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcgi_stdio.h>

int main() {
    while(FCGI_Accept() == 0) {
        std::string remote_addr;
            
        const char* proxy_remote = getenv("HTTP_X_FORWARDED_FOR");

        if (!proxy_remote) {
            const char* direct_remote = getenv("REMOTE_ADDR");
            remote_addr = std::string(direct_remote);
        } else {
            remote_addr = std::string(proxy_remote);
        }

        std::cout << "Content-Type: text/plain\n" << "\n" << remote_addr << std::endl;
    }

	return 0;
}
