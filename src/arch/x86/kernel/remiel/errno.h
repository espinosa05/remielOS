#if !defined(REMIEL_ERRNO_H)
#define REMIEL_ERRNO_H

typedef err_t size_t;

void __set_remiel_internal_errno(err_t errnoval);

#endif /* REMIEL_ERRNO_H */