#if !defined(REMIEL_ASSERTIONS_H)
#define REMIEL_ASSERTIONS_H

#define ASSERT_OR_RETURN(expression, retval) \
  if (!expression)                           \
    return retval;

#endif /* REMIEL_ASSERTIONS_H */