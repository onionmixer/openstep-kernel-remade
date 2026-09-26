/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115ed4. */
int __cdecl sogetopt(__int16 *a1, int a2, int a3, int **a4)
{
  int v4; // eax
  int (__stdcall *v5)(_DWORD, __int16 *, int, int, int **); // eax
  int *v7; // eax

  if ( a2 == 0xFFFF ) /*0x115eec*/
  {
    v7 = m_get(1, 10); /*0x115f1c*/
    *((_WORD *)v7 + 4) = 4; /*0x115f23*/
    if ( a3 != 256 ) /*0x115f32*/
    {
      if ( a3 > 256 ) /*0x115f38*/
      {
        if ( a3 == 4100 ) /*0x115fa2*/
        {
          *(int *)((char *)v7 + v7[1]) = (unsigned __int16)a1[22]; /*0x11607b*/
        }
        else if ( a3 > 4100 ) /*0x115fa8*/
        {
          if ( a3 == 4102 ) /*0x115fd6*/
          {
            *(int *)((char *)v7 + v7[1]) = a1[23]; /*0x116093*/
          }
          else if ( a3 < 4102 ) /*0x115fdc*/
          {
            *(int *)((char *)v7 + v7[1]) = a1[35]; /*0x116087*/
          }
          else if ( a3 == 4103 ) /*0x115fe8*/
          {
            *(int *)((char *)v7 + v7[1]) = (unsigned __int16)a1[43]; /*0x116043*/
            a1[43] = 0; /*0x116046*/
          }
          else
          {
            if ( a3 != 4104 ) /*0x115ff0*/
              goto LABEL_43; /*0x115ff0*/
            *(int *)((char *)v7 + v7[1]) = *a1; /*0x116036*/
          }
        }
        else if ( a3 == 4098 ) /*0x115fb0*/
        {
          *(int *)((char *)v7 + v7[1]) = (unsigned __int16)a1[19]; /*0x116063*/
        }
        else if ( a3 > 4098 ) /*0x115fb6*/
        {
          *(int *)((char *)v7 + v7[1]) = (unsigned __int16)a1[34]; /*0x11606f*/
        }
        else
        {
          if ( a3 != 4097 ) /*0x115fc2*/
            goto LABEL_43; /*0x115fc2*/
          *(int *)((char *)v7 + v7[1]) = (unsigned __int16)a1[31]; /*0x116057*/
        }
        goto LABEL_44; /*0x11605a*/
      }
      if ( a3 != 16 ) /*0x115f3d*/
      {
        if ( a3 <= 16 ) /*0x115f43*/
        {
          if ( a3 != 4 ) /*0x115f48*/
          {
            if ( a3 > 4 ) /*0x115f4e*/
            {
              if ( a3 != 8 ) /*0x115f63*/
                goto LABEL_43; /*0x115f63*/
            }
            else if ( a3 != 1 ) /*0x115f53*/
            {
LABEL_43:
              m_free((int)v7); /*0x116098*/
              return 42; /*0x1160a3*/
            }
          }
          goto LABEL_34; /*0x115f53*/
        }
        if ( a3 != 64 ) /*0x115f73*/
        {
          if ( a3 <= 64 ) /*0x115f79*/
          {
            if ( a3 != 32 ) /*0x115f7e*/
              goto LABEL_43; /*0x115f7e*/
            goto LABEL_34; /*0x115f7e*/
          }
          if ( a3 != 128 ) /*0x115f92*/
            goto LABEL_43; /*0x115f92*/
          *((_WORD *)v7 + 4) = 8; /*0x115ff8*/
          *(int *)((char *)v7 + v7[1]) = a1[1] & 0x80; /*0x11600a*/
          *(int *)((char *)v7 + v7[1] + 4) = a1[2]; /*0x116014*/
LABEL_44:
          *a4 = v7; /*0x1160a8*/
          return 0; /*0x1160aa*/
        }
      }
    }
LABEL_34:
    *(int *)((char *)v7 + v7[1]) = a3 & a1[1]; /*0x116020*/
    goto LABEL_44; /*0x11602c*/
  }
  v4 = *((_DWORD *)a1 + 3); /*0x115eee*/
  if ( v4 && (v5 = *(int (__stdcall **)(_DWORD, __int16 *, int, int, int **))(v4 + 24)) != nullptr ) /*0x115efa*/
    return v5(0, a1, a2, a3, a4); /*0x115f02*/
  else
    return 42; /*0x115f0c*/
}
