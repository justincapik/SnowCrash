#include <unistd.h>

int main(int argc, char **argv)
{
	gid_t gid = getegid();
	uid_t uid = geteuid();

	setresuid(uid, uid, uid);
	setresgid(gid, gid, gid);
	write(1, "Exploit me\n", 11);
}
