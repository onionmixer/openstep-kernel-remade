/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9aa4. */
id __cdecl -[InputStream completeRegion:descriptor:size:used:](
        InputStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a4,
        unsigned int a5,
        unsigned int *a6)
{
  void *var3; // ecx
  size_t v7; // edi
  unsigned int v8; // edx
  __int16 *v9; // edx
  _WORD *v10; // ebx
  int dataFormat; // eax
  size_t j; // ecx
  __int16 v13; // ax
  _BYTE *v14; // ebx
  size_t i; // ecx
  size_t v17; // [esp+Ch] [ebp-8h]
  __int16 *v18; // [esp+10h] [ebp-4h]

  var3 = (void *)a3->var3; /*0x1b9ab3*/
  v7 = a3->var2 - (_DWORD)var3; /*0x1b9ab9*/
  v17 = v7; /*0x1b9abb*/
  if ( a5 && v7 ) /*0x1b9ac8*/
  {
    v8 = *a6; /*0x1b9ad1*/
    if ( *a6 + v7 > a5 ) /*0x1b9ad9*/
      v17 = a5 - v8; /*0x1b9add*/
    v9 = (__int16 *)(a4->var1 + v8); /*0x1b9ae3*/
    v10 = (_WORD *)a3->var3; /*0x1b9ae6*/
    dataFormat = self->super.dataFormat; /*0x1b9aeb*/
    if ( dataFormat ) /*0x1b9af0*/
    {
      if ( dataFormat == 3 ) /*0x1b9b1b*/
      {
        v18 = v9; /*0x1b9b1d*/
        v14 = (_BYTE *)a3->var3; /*0x1b9b20*/
        for ( i = 0; v17 > i; ++i ) /*0x1b9b27*/
        {
          *v14++ = *(_BYTE *)v18 & 0x7F | *(_BYTE *)v18 ^ 0x80; /*0x1b9b3a*/
          v18 = (__int16 *)((char *)v18 + 1); /*0x1b9b3e*/
        }
      }
      else if ( dataFormat == 1 ) /*0x1b9b4f*/
      {
        bcopy(v9, var3, v17); /*0x1b9b57*/
      }
    }
    else
    {
      for ( j = 0; v17 >> 1 > j; ++j ) /*0x1b9af7*/
      {
        v13 = *v9++; /*0x1b9b00*/
        *v10++ = __ROR2__(v13, 8); /*0x1b9b0a*/
      }
    }
    *a6 += v17; /*0x1b9b65*/
    a3->var3 += v17; /*0x1b9b6a*/
    self->super.bytesProcessed += v17; /*0x1b9b70*/
  }
  if ( ($2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *)a3->var9 == a4 || a3->var10.var2 ) /*0x1b9b7e*/
    -[InputStream sendRecordedDataForRegion:](self, sel_sendRecordedDataForRegion_, a3); /*0x1b9b93*/
  return self; /*0x1b9b9e*/
}
