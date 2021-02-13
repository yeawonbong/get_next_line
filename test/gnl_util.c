size_t              ft_strlen(char *a)
{
    size_t          i;
    i = 0;
    while (a[i])
    {
        i++;
    }
    return (i);
}
char                *ft_strndup(const char *src, size_t len)
{
    char            *msrc;
    size_t          i;
    msrc = (char*)malloc(sizeof(char) * len + 1);
    if (msrc == 0)
        return (0);
    i = 0;
    ft_strlcpy(msrc, (char*)src, len + 1);
    return (&msrc[0]);
}
size_t              ft_strlcpy(char *dest, char *src, size_t size)
{
    size_t          i;
    size_t          j;
    i = 0;
    j = 0;
    if (!dest || !src)
        return (0);
    while (src[i])
        i++;
    if (size != 0)
    {
        while (j < size - 1 && src[j])
        {
            dest[j] = src[j];
            ++j;
        }
        dest[j] = '\0';
    }
    return (i);
}
char                *ft_strjoin(char const *s1, char const *s2)
{
    char            *js;
    size_t          i;
    size_t          s1len;
    size_t          s2len;
    i = 0;
    if (!s1)
        return ((char *)s1);
    if (!s2)
        return ((char *)s2);
    s1len = ft_strlen((char*)s1);
    s2len = ft_strlen((char*)s2);
    if (!(js = (char*)malloc(sizeof(char) * (s1len + s2len + 1))))
        return (NULL);
    js[s1len + s2len] = '\0';
    while (*s1)
        js[i++] = *s1++;
    while (*s2)
        js[i++] = *s2++;
    return (js);
}
char                *ft_substr(char const *s, size_t start, size_t len)
{
    char            *substr;
    size_t          size;
    if (!s)
        return (0);
    if (!(substr = (char*)malloc(sizeof(char) * len + 1)))
        return (0);
    size = ft_strlen((char*)s);
    if (start >= size)
    {
        substr[0] = 0;
        return (substr);
    }
    ft_strlcpy(substr, (char*)(s + start), len + 1);
    return (substr);
}

static char         *ft_strchr(const char *str, int c)
{
    int i;
    i = 0;
    while (str[i] != (char)c)
    {
        if (!str[i])
            return (NULL);
        i++;
    }
    return ((char*)&str[i]);
}