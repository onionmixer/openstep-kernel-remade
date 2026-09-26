/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccda0. */
void __cdecl sub_1CCDA0(_DWORD *a1, char a2)
{
  NXHashTable *Classes; // esi
  _DWORD *v3; // edx
  void *data; // [esp+Ch] [ebp-Ch] BYREF
  NXHashState state; // [esp+10h] [ebp-8h] BYREF

  if ( a1[8] ) /*0x1ccdb1*/
  {
    Classes = (NXHashTable *)objc_getClasses(); /*0x1ccdc0*/
    state = NXInitHashState(Classes); /*0x1ccdc8*/
LABEL_3:
    while ( NXNextHashState(Classes, &state, &data) ) /*0x1ccde7*/
    {
      v3 = data; /*0x1ccde9*/
      if ( data ) /*0x1ccdee*/
      {
        while ( v3 != a1 ) /*0x1ccdf2*/
        {
          if ( (_DWORD *)*v3 == a1 ) /*0x1cce16*/
          {
            sub_1CD7EC(data); /*0x1cce1c*/
            v3 = nullptr; /*0x1cce21*/
          }
          else if ( (v3[4] & 4) != 0 ) /*0x1cce2c*/
          {
            v3 = (_DWORD *)v3[1]; /*0x1cce2e*/
          }
          else
          {
            v3 = nullptr; /*0x1cce34*/
          }
          if ( !v3 ) /*0x1cce38*/
            goto LABEL_3; /*0x1cce38*/
        }
        sub_1CD7EC(data); /*0x1ccdf8*/
        if ( a2 ) /*0x1cce04*/
          sub_1CD7EC(*(_DWORD *)data); /*0x1cce0c*/
      }
    }
  }
}
