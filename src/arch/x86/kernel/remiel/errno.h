#if !defined(REMIEL_ERRNO_H)
#define REMIEL_ERRNO_H

typedef err_t size_t;

extern err_t errno;
void set_remiel_errno(err_t errnoval);

#endif /* REMIEL_ERRNO_H */