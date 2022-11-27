#include <remiel/errno.h>


static err_t errno;

err_t __get_remiel_errno()
{
  return errno;
}

void __set_remiel_internal_errno(err_t errnoval)
{
  errno = errnoval;
}