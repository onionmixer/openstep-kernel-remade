/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5220. */
const char *__cdecl -[IOConfigTable valueForStringKey:](IOConfigTable *self, SEL a2, const char *a3)
{
  const char *v3; // esi
  unsigned int v4; // kr04_4
  unsigned int v5; // edi
  int v6; // eax
  void *v7; // esp
  char *v8; // eax
  const char *v10; // ebx
  char *v11; // eax
  size_t v12; // edi
  char *v13; // esi
  char v14; // [esp+0h] [ebp-14h] BYREF
  char v15[11]; // [esp+1h] [ebp-13h] BYREF
  char *v16; // [esp+Ch] [ebp-8h]
  unsigned int v17; // [esp+10h] [ebp-4h]

  v3 = (const char *)self->_private; /*0x1a522f*/
  v4 = strlen(a3) + 1; /*0x1a523c*/
  v5 = v4 - 1; /*0x1a5242*/
  v16 = &v14; /*0x1a5245*/
  v17 = v4 + 1; /*0x1a524b*/
  v6 = v4 + 5; /*0x1a524e*/
  LOBYTE(v6) = (v4 + 5) & 0xFC; /*0x1a5251*/
  v7 = alloca(v6); /*0x1a5253*/
  v14 = 34; /*0x1a5257*/
  strcpy(v15, a3); /*0x1a5260*/
  v15[v5] = 34; /*0x1a5265*/
  v15[v5 + 1] = 0; /*0x1a526a*/
  v8 = strstr(v3, &v14); /*0x1a5271*/
  if ( !v8 ) /*0x1a527a*/
    return nullptr; /*0x1a527c*/
  v10 = strchr(&v8[v17], 34) + 1; /*0x1a5290*/
  v11 = strchr(v10, 34); /*0x1a5294*/
  if ( !v11 ) /*0x1a529e*/
    return nullptr; /*0x1a52c0*/
  v12 = v11 - v10; /*0x1a52a2*/
  v13 = (char *)IOMalloc(v11 - v10 + 1); /*0x1a52ad*/
  strncpy(v13, v10, v12); /*0x1a52b2*/
  v13[v12] = 0; /*0x1a52b7*/
  return v13; /*0x1a52c5*/
}
