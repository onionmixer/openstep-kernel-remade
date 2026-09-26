/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1600cc. */
int __cdecl sub_1600CC(char *a1)
{
  char **v1; // esi
  char *v2; // ecx
  char *v3; // ebx
  char v4; // dl
  char v5; // al
  char **v6; // esi
  char *v7; // ecx
  char *v8; // ebx
  char v9; // dl
  char v10; // al
  char **v12; // [esp+Ch] [ebp-4h]

  v12 = nullptr; /*0x1600d5*/
  v1 = &miniMonCommands; /*0x1600dc*/
  if ( miniMonCommands ) /*0x1600e8*/
  {
    while ( 1 ) /*0x1600ec*/
    {
      v2 = *v1; /*0x1600ec*/
      v3 = a1; /*0x1600ee*/
      while ( *v2 ) /*0x1600f1*/
      {
        v4 = *v3; /*0x1600f8*/
        if ( *v3 == 32 || (unsigned __int8)(v4 - 9) <= 1u || !v4 ) /*0x160109*/
          break; /*0x160109*/
        v5 = *v2; /*0x16010b*/
        ++v3; /*0x16010d*/
        ++v2; /*0x16010e*/
        if ( v5 != v4 ) /*0x160111*/
          goto LABEL_10; /*0x160111*/
      }
      if ( v12 ) /*0x16011c*/
        break; /*0x16011c*/
      v12 = v1; /*0x16011e*/
LABEL_10:
      v1 += 3; /*0x160121*/
      if ( !*v1 ) /*0x160124*/
        goto LABEL_11; /*0x160127*/
    }
    safe_prf(aAmbiguousComma); /*0x160191*/
  }
  else
  {
LABEL_11:
    v6 = &miniMonMDCommands; /*0x160129*/
    if ( miniMonMDCommands ) /*0x160135*/
    {
      while ( 1 ) /*0x160138*/
      {
        v7 = *v6; /*0x160138*/
        v8 = a1; /*0x16013a*/
        while ( *v7 ) /*0x16013d*/
        {
          v9 = *v8; /*0x160144*/
          if ( *v8 == 32 || (unsigned __int8)(v9 - 9) <= 1u || !v9 ) /*0x160155*/
            break; /*0x160155*/
          v10 = *v7; /*0x160157*/
          ++v8; /*0x160159*/
          ++v7; /*0x16015a*/
          if ( v10 != v9 ) /*0x16015d*/
            goto LABEL_20; /*0x16015d*/
        }
        if ( v12 ) /*0x160168*/
          break; /*0x160168*/
        v12 = v6; /*0x16016a*/
LABEL_20:
        v6 += 3; /*0x16016d*/
        if ( !*v6 ) /*0x160170*/
          goto LABEL_21; /*0x160173*/
      }
      safe_prf(aAmbiguousComma_0); /*0x160199*/
    }
    else
    {
LABEL_21:
      if ( v12 ) /*0x160179*/
        return ((int (__cdecl *)(char *))v12[1])(a1); /*0x160187*/
      safe_prf(aInvalidCommand); /*0x1601a1*/
    }
  }
  return 1; /*0x1601ae*/
}
