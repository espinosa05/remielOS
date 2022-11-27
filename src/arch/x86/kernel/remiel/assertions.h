#if !defined(REMIEL_ASSERTIONS_H)
#define REMIEL_ASSERTIONS_H

#define ASSERT_OR_RETURN_VAL(expression, retval)  \
  if (!expression)                                \
    return retval

#define ASSERT_OR_RETURN(expression)  \
  if (!expression)                    \
      return

#endif /* REMIEL_ASSERTIONS_H */