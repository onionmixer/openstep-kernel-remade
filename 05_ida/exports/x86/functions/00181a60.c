/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181a60. */
KernStringList *__cdecl -[KernStringList initWithWhitespaceDelimitedString:](
        KernStringList *self,
        SEL a2,
        const char *a3)
{
  const char *i; // ecx
  const char *v4; // edi
  char *j; // ecx
  char *v6; // edi
  char *v7; // eax
  unsigned int v9; // [esp+Ch] [ebp-1Ch]
  size_t __n; // [esp+10h] [ebp-18h]
  char *__src; // [esp+14h] [ebp-14h]
  char *__srca; // [esp+14h] [ebp-14h]
  char *v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  objc_super v15; // [esp+20h] [ebp-8h] BYREF

  v15.receiver = self; /*0x181a76*/
  v15.super_class = (Class)stru_1F9FC4.ext; /*0x181a7f*/
  -[Object init](&v15, sel_init); /*0x181a89*/
  for ( i = a3; *i; ++i ) /*0x181a94*/
  {
    if ( *i != 32 && (unsigned __int8)(*i - 9) > 1u ) /*0x181aa6*/
      break; /*0x181aa6*/
  }
  v4 = i; /*0x181aae*/
  if ( *i ) /*0x181ab0*/
  {
    do /*0x181ac5*/
    {
LABEL_6:
      if ( *v4 != 32 && (unsigned __int8)(*v4 - 9) > 1u ) /*0x181ac2*/
        break; /*0x181ac2*/
      ++v4; /*0x181ac4*/
    }
    while ( *v4 ); /*0x181ac5*/
    if ( *v4 ) /*0x181aca*/
    {
      ++self->count; /*0x181ad2*/
      while ( *v4 ) /*0x181ae5*/
      {
        if ( *v4 == 32 || (unsigned __int8)(*v4 - 9) <= 1u ) /*0x181ade*/
        {
          if ( *v4 ) /*0x181aeb*/
            goto LABEL_6; /*0x181aee*/
          break; /*0x181aee*/
        }
        ++v4; /*0x181ae0*/
      }
    }
  }
  __src = (char *)i; /*0x181af0*/
  self->strings = (char **)IOMalloc(4 * self->count); /*0x181b0c*/
  v14 = 0; /*0x181b0f*/
  for ( j = __src; j; ++v14 ) /*0x181b1b*/
  {
    if ( !*j ) /*0x181b24*/
      break; /*0x181b28*/
    v6 = j; /*0x181b2e*/
    while ( *v6 != 32 ) /*0x181b32*/
    {
      if ( (unsigned __int8)(*v6 - 9) <= 1u ) /*0x181b3a*/
        break; /*0x181b3a*/
      if ( !*++v6 ) /*0x181b3d*/
        break; /*0x181b41*/
    }
    __n = v6 - j; /*0x181b4b*/
    v9 = v6 - j + 1; /*0x181b4f*/
    __srca = j; /*0x181b53*/
    v7 = (char *)IOMalloc(v9); /*0x181b56*/
    self->strings[v14] = v7; /*0x181b69*/
    v13 = v7; /*0x181b75*/
    strncpy(v7, __srca, __n); /*0x181b78*/
    v13[v9 - 1] = 0; /*0x181b83*/
    for ( j = v6; *j; ++j ) /*0x181b8d*/
    {
      if ( *j != 32 && (unsigned __int8)(*j - 9) > 1u ) /*0x181b9e*/
        break; /*0x181b9e*/
    }
  }
  return self; /*0x181bb7*/
}
