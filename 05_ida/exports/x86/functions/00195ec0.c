/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195ec0. */
int (__cdecl **__cdecl DoAlert(int a1, _BYTE *a2))(id, int, _DWORD, int, int)
{
  _BYTE *v2; // ebx
  int (__cdecl **result)(id, int, _DWORD, int, int); // eax
  int v4; // eax
  _DWORD *v5; // esi
  id Console; // eax
  _DWORD *v7; // eax
  int v8; // esi
  int v9; // [esp-4h] [ebp-10h]
  int v10; // [esp-4h] [ebp-10h]
  int v11; // [esp-4h] [ebp-10h]

  v2 = a2; /*0x195ec9*/
  result = (int (__cdecl **)(id, int, _DWORD, int, int))kmId; /*0x195ecc*/
  if ( kmId ) /*0x195ed3*/
  {
    dword_1E776C(*((_DWORD *)kmId + 66), sel_lock); /*0x195f8b*/
    v4 = *((_DWORD *)kmId + 69); /*0x195f96*/
    if ( v4 != 1 && v4 != 3 ) /*0x195fa8*/
    {
      v5 = kmId; /*0x195faa*/
      if ( dword_1E7768 ) /*0x195fb3*/
        Console = objc_msgSend(dword_1E7768, sel_allocateConsoleInfo); /*0x195fc4*/
      else
        Console = (id)BasicAllocateConsole(); /*0x195fb5*/
      v5[68] = Console; /*0x195fcc*/
      if ( !*((_DWORD *)kmId + 68) ) /*0x195fd7*/
        *((_DWORD *)kmId + 68) = basicConsole; /*0x195fe6*/
      (*(void (__cdecl **)(_DWORD, int, _DWORD, int, int))(*((_DWORD *)kmId + 68) + 4))( /*0x196002*/
        *((_DWORD *)kmId + 68),
        3,
        0,
        1,
        a1);
      v7 = kmId; /*0x196004*/
      *((_DWORD *)kmId + 70) = *((_DWORD *)kmId + 69); /*0x19600f*/
      v7[69] = 3; /*0x196015*/
      ++v7[71]; /*0x19601f*/
    }
    dword_1E7770(*((_DWORD *)kmId + 66), sel_unlock); /*0x196040*/
    result = (int (__cdecl **)(id, int, _DWORD, int, int))kmId; /*0x196042*/
    if ( *((_DWORD *)kmId + 69) == 3 ) /*0x196051*/
      v8 = *((_DWORD *)kmId + 68); /*0x196053*/
    else
      v8 = *((_DWORD *)kmId + 67); /*0x19605c*/
    while ( *v2 ) /*0x196075*/
    {
      v11 = (char)*v2++; /*0x196067*/
      result = (int (__cdecl **)(id, int, _DWORD, int, int))(*(int (__cdecl **)(int, int))(v8 + 20))(v8, v11); /*0x19606d*/
    }
  }
  else if ( !kmAlertConsole ) /*0x195ee0*/
  {
    result = (int (__cdecl **)(id, int, _DWORD, int, int))basicConsoleMode; /*0x195ee6*/
    if ( basicConsoleMode == 3 || basicConsoleMode == 1 ) /*0x195ef3*/
    {
      if ( basicConsole && *a2 ) /*0x195f02*/
      {
        do /*0x195f1f*/
        {
          v9 = (char)*v2++; /*0x195f14*/
          result = (int (__cdecl **)(id, int, _DWORD, int, int))(*(int (__cdecl **)(int, int))(basicConsole + 20))( /*0x195f1a*/
                                                                  basicConsole,
                                                                  v9);
        }
        while ( *v2 ); /*0x195f1f*/
      }
    }
    else
    {
      result = (int (__cdecl **)(id, int, _DWORD, int, int))BasicAllocateConsole(); /*0x195f2c*/
      kmAlertConsole = (int)result; /*0x195f31*/
      if ( result ) /*0x195f38*/
      {
        result = (int (__cdecl **)(id, int, _DWORD, int, int))result[1](result, 3, 0, 1, a1); /*0x195f49*/
        if ( *a2 ) /*0x195f4e*/
        {
          do /*0x195f6b*/
          {
            v10 = (char)*v2++; /*0x195f60*/
            result = (int (__cdecl **)(id, int, _DWORD, int, int))(*(int (__cdecl **)(int, int))(kmAlertConsole + 20))( /*0x195f66*/
                                                                    kmAlertConsole,
                                                                    v10);
          }
          while ( *v2 ); /*0x195f6b*/
        }
      }
    }
  }
  return result; /*0x19607a*/
}
