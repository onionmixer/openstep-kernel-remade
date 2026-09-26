/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9368. */
id __cdecl -[AudioStream free](AudioStream *self, SEL a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *sndReplyMsg; // eax
  int userPort; // [esp-Ch] [ebp-18h]
  int pausePort; // [esp-4h] [ebp-10h]
  int resumePort; // [esp-4h] [ebp-10h]
  int abortPort; // [esp-4h] [ebp-10h]
  objc_super v12; // [esp+4h] [ebp-8h] BYREF

  if ( self->pausePort ) /*0x1b9372*/
  {
    pausePort = self->pausePort; /*0x1b9379*/
    v2 = task_self(); /*0x1b937a*/
    port_deallocate_EXTERNAL(v2, pausePort); /*0x1b9380*/
  }
  if ( self->resumePort ) /*0x1b9388*/
  {
    resumePort = self->resumePort; /*0x1b938f*/
    v3 = task_self(); /*0x1b9390*/
    port_deallocate_EXTERNAL(v3, resumePort); /*0x1b9396*/
  }
  if ( self->abortPort ) /*0x1b939e*/
  {
    abortPort = self->abortPort; /*0x1b93a5*/
    v4 = task_self(); /*0x1b93a6*/
    port_deallocate_EXTERNAL(v4, abortPort); /*0x1b93ac*/
  }
  -[AudioStream freeRegions](self, sel_freeRegions); /*0x1b93bc*/
  userPort = self->userPort; /*0x1b93c4*/
  v5 = task_self(); /*0x1b93c5*/
  if ( port_deallocate_EXTERNAL(v5, userPort) )
    IOLog((int)"Audio: stream port_deallocate: %s\n", "MACH ERR");
  objc_msgSend(self->regionQueueLock, sel_free); /*0x1b93f4*/
  sndReplyMsg = self->sndReplyMsg; /*0x1b93fc*/
  if ( sndReplyMsg ) /*0x1b9401*/
    IOFree((int)sndReplyMsg, 0x2000); /*0x1b9409*/
  v12.receiver = self; /*0x1b9418*/
  v12.super_class = (Class)stru_1FA4C4.super_class; /*0x1b9421*/
  return -[Object free](&v12, sel_free); /*0x1b942d*/
}
