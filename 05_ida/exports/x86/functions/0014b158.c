/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b158. */
char ipc_notify_init()
{
  __int16 v0; // ax
  char result; // al

  ipc_notify_port_deleted_template = 18; /*0x14b15b*/
  dword_1F62D4 = 32; /*0x14b165*/
  dword_1F62E0 = 1; /*0x14b16f*/
  dword_1F62DC = 0; /*0x14b179*/
  dword_1F62D8 = 0; /*0x14b183*/
  dword_1F62E4 = 65; /*0x14b18d*/
  byte_1F62E8 = 15; /*0x14b197*/
  byte_1F62E9 = 32; /*0x14b19e*/
  HIBYTE(v0) = HIBYTE(word_1F62EA) & 0xF0; /*0x14b1ab*/
  LOBYTE(v0) = 1; /*0x14b1af*/
  word_1F62EA = v0; /*0x14b1b1*/
  HIBYTE(word_1F62EA) = HIBYTE(v0) & 0xF | 0x10; /*0x14b1c1*/
  dword_1F62EC = 0; /*0x14b1c7*/
  ipc_notify_msg_accepted_template = 18; /*0x14b1d1*/
  dword_1F6294 = 32; /*0x14b1db*/
  dword_1F62A0 = 1; /*0x14b1e5*/
  dword_1F629C = 0; /*0x14b1ef*/
  dword_1F6298 = 0; /*0x14b1f9*/
  dword_1F62A4 = 66; /*0x14b203*/
  byte_1F62A8 = 15; /*0x14b20d*/
  byte_1F62A9 = 32; /*0x14b214*/
  HIBYTE(v0) = HIBYTE(word_1F62AA) & 0xF0; /*0x14b221*/
  LOBYTE(v0) = 1; /*0x14b225*/
  word_1F62AA = v0; /*0x14b227*/
  HIBYTE(word_1F62AA) = HIBYTE(v0) & 0xF | 0x10; /*0x14b237*/
  dword_1F62AC = 0; /*0x14b23d*/
  ipc_notify_port_destroyed_template = -2147483630; /*0x14b247*/
  dword_1F62F4 = 32; /*0x14b251*/
  dword_1F6300 = 1; /*0x14b25b*/
  dword_1F62FC = 0; /*0x14b265*/
  dword_1F62F8 = 0; /*0x14b26f*/
  dword_1F6304 = 69; /*0x14b279*/
  byte_1F6308 = 16; /*0x14b283*/
  byte_1F6309 = 32; /*0x14b28a*/
  HIBYTE(v0) = HIBYTE(word_1F630A) & 0xF0; /*0x14b297*/
  LOBYTE(v0) = 1; /*0x14b29b*/
  word_1F630A = v0; /*0x14b29d*/
  HIBYTE(word_1F630A) = HIBYTE(v0) & 0xF | 0x10; /*0x14b2ad*/
  dword_1F630C = 0; /*0x14b2b3*/
  ipc_notify_no_senders_template = 18; /*0x14b2bd*/
  dword_1F62B4 = 32; /*0x14b2c7*/
  dword_1F62C0 = 1; /*0x14b2d1*/
  dword_1F62BC = 0; /*0x14b2db*/
  dword_1F62B8 = 0; /*0x14b2e5*/
  dword_1F62C4 = 70; /*0x14b2ef*/
  byte_1F62C8 = 2; /*0x14b2f9*/
  byte_1F62C9 = 32; /*0x14b300*/
  HIBYTE(v0) = HIBYTE(word_1F62CA) & 0xF0; /*0x14b30d*/
  LOBYTE(v0) = 1; /*0x14b311*/
  word_1F62CA = v0; /*0x14b313*/
  HIBYTE(word_1F62CA) = HIBYTE(v0) & 0xF | 0x10; /*0x14b323*/
  dword_1F62CC = 0; /*0x14b329*/
  ipc_notify_send_once_template = 18; /*0x14b333*/
  dword_1F6314 = 24; /*0x14b33d*/
  dword_1F6320 = 1; /*0x14b347*/
  dword_1F631C = 0; /*0x14b351*/
  dword_1F6318 = 0; /*0x14b35b*/
  dword_1F6324 = 71; /*0x14b365*/
  ipc_notify_dead_name_template = 18; /*0x14b36f*/
  dword_1F6274 = 32; /*0x14b379*/
  dword_1F6280 = 1; /*0x14b383*/
  dword_1F627C = 0; /*0x14b38d*/
  dword_1F6278 = 0; /*0x14b397*/
  dword_1F6284 = 72; /*0x14b3a1*/
  byte_1F6288 = 15; /*0x14b3ab*/
  byte_1F6289 = 32; /*0x14b3b2*/
  HIBYTE(v0) = HIBYTE(word_1F628A) & 0xF0; /*0x14b3bf*/
  LOBYTE(v0) = 1; /*0x14b3c3*/
  word_1F628A = v0; /*0x14b3c5*/
  result = HIBYTE(v0) & 0xF | 0x10; /*0x14b3d3*/
  HIBYTE(word_1F628A) = result; /*0x14b3d5*/
  dword_1F628C = 0; /*0x14b3db*/
  return result; /*0x14b3e7*/
}
