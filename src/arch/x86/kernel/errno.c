#include <remiel/errno.h>


err_t errno;

void set_remiel_errno(err_t errnoval)
{
  errno = errnoval;
}