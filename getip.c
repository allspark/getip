/* getip: A small fastcgi handler that returns the client's IP address.
 * Author: Lukas Martini <lutoma@ohai.su>
 * Author: Moritz Kaspar Rudert (mortzu) <me@mortzu.de>
 *
 * To the extent possible under law, Lukas Martini has waived all copyright and
 * related or neighboring rights to getip. This work is published from: United
 * States.
 *
 * For more information and the legal code, see
 * http://creativecommons.org/publicdomain/zero/1.0/legalcode
 */

#include <fcgi_stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	while (FCGI_Accept() >= 0)
		printf("Content-Type: text/plain\r\n"
			"X-Sourcecode: https://github.com/mortzu/getip\r\n"
			"\r\n%s\r\n",
			getenv("REMOTE_ADDR"));

	return EXIT_SUCCESS;
}
