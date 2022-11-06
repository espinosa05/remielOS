#if !defined(REMIEL_GFP_H)
#define REMIEL_GFP_H

enum gfp_flags
{
    GFP_ATOMIC  = 1,
    GFP_KERNEL  = 1 << 1,
    GFP_USER    = 1 << 2,
    GFP_HIGHUSER = 1 << 3,
    GFP_NOIO    = 1 << 4,
    GFP_NOFS    = 1 << 5,
};

#endif /* REMIEL_GFP_H */
