/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1c80. */
int __cdecl -[EventDriver _threadOpCommon:opParams:async:](EventDriver *self, SEL a2, int a3, void *a4, char a5)
{
  int v5; // eax
  const char *v6; // eax
  int v8; // [esp-4h] [ebp-4Ch]
  int v9; // [esp+10h] [ebp-38h] BYREF
  _DWORD v10[13]; // [esp+14h] [ebp-34h] BYREF

  qmemcpy(v10, &unk_1E5330, sizeof(v10)); /*0x1b1ca0*/
  v10[3] = 0; /*0x1b1ca2*/
  v10[7] = a3; /*0x1b1cac*/
  if ( !a5 ) /*0x1b1cb3*/
  {
    v10[8] = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1b1cc8*/
    objc_msgSend((id)v10[8], sel_initWith_, 1); /*0x1b1cd5*/
    v10[9] = &v9; /*0x1b1cdd*/
    v9 = -706; /*0x1b1ce0*/
  }
  v10[10] = *(_DWORD *)a4; /*0x1b1cec*/
  v10[11] = *((_DWORD *)a4 + 1); /*0x1b1cf2*/
  v10[12] = *((_DWORD *)a4 + 2); /*0x1b1cf8*/
  v10[4] = ev_port_list[0]; /*0x1b1d01*/
  v5 = msg_send_from_kernel(v10, 0, 0); /*0x1b1d0c*/
  if ( v5 )
  {
    v8 = v5; /*0x1b1d18*/
    v6 = -[IODevice name](self, sel_name); /*0x1b1d24*/
    IOLog((int)"%s: _threadOpCommon msg_send returned %d\n", v6, v8);
    v9 = -703; /*0x1b1d37*/
  }
  else if ( a5 ) /*0x1b1d48*/
  {
    v9 = 0; /*0x1b1d64*/
  }
  else
  {
    objc_msgSend((id)v10[8], sel_lockWhen_, 2); /*0x1b1d57*/
  }
  if ( !a5 ) /*0x1b1d6f*/
    objc_msgSend((id)v10[8], sel_free); /*0x1b1d7c*/
  return v9; /*0x1b1d87*/
}
