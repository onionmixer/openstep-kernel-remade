/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8598. */
id __cdecl -[AudioStream control:atTime:](AudioStream *self, SEL a2, int a3, timeval a4)
{
  _DWORD *v4; // ebx
  int v5; // eax
  NXLock *v6; // eax
  task_t v7; // eax
  timeval *p_resumeTime; // ecx
  int v9; // eax
  NXLock *v10; // eax
  task_t v11; // eax
  id v12; // eax
  int v13; // eax
  NXLock *v14; // eax
  task_t v15; // eax
  int v17; // [esp-8h] [ebp-2Ch]
  int v18; // [esp-8h] [ebp-2Ch]
  int v19; // [esp-8h] [ebp-2Ch]

  if ( a3 == 1 )
  {
    if ( !*(_QWORD *)&a4 ) /*0x1b8700*/
    {
      self->isPaused = 0; /*0x1b8803*/
      -[AudioStream sendControlMessage:mask:](self, sel_sendControlMessage_mask_, 3, 8); /*0x1b8813*/
      v12 = -[AudioStream channel](self, sel_channel); /*0x1b8823*/
      objc_msgSend(self->device, sel__dataPendingForChannel_, v12); /*0x1b8837*/
      return self; /*0x1b883c*/
    }
    self->resumeTime = a4; /*0x1b870f*/
    v4 = (_DWORD *)IOMalloc(0x28u); /*0x1b872b*/
    if ( !self->resumePort )
    {
      v9 = task_self(); /*0x1b8741*/
      if ( port_allocate_EXTERNAL(v9) )
      {
        IOLog("Audio: stream control thread port_allocate: %s\n");
        IOLog("Audio Driver error"); /*0x1b8767*/
      }
      if ( !dword_1E53A8 ) /*0x1b8776*/
      {
        v10 = +[Object alloc](aNxlock, sel_alloc); /*0x1b878d*/
        dword_1E53A8 = -[NXLock init](v10, sel_init); /*0x1b879b*/
      }
      objc_msgSend(dword_1E53A8, sel_lock); /*0x1b87b1*/
      dword_1E53A4 = self->resumePort; /*0x1b87bc*/
      v11 = current_task_EXTERNAL(); /*0x1b87c7*/
      kernel_thread(v11, (int)sub_1B9160, v18); /*0x1b87cd*/
    }
    qmemcpy(v4, &unk_1D5E6C, 0x28u); /*0x1b87e2*/
    v4[4] = self->resumePort; /*0x1b87e9*/
    v4[7] = self; /*0x1b87ef*/
    v4[8] = 1; /*0x1b87f5*/
    p_resumeTime = &self->resumeTime; /*0x1b87f8*/
    goto LABEL_32; /*0x1b87fb*/
  }
  if ( !a3 )
  {
    if ( __PAIR64__(a4.tv_sec, 0) == a4.tv_usec ) /*0x1b85dc*/
    {
      self->isPaused = 1; /*0x1b86df*/
      -[AudioStream sendControlMessage:mask:](self, sel_sendControlMessage_mask_, 2, 4); /*0x1b86ef*/
      return self; /*0x1b86f4*/
    }
    self->pauseTime = a4; /*0x1b85eb*/
    v4 = (_DWORD *)IOMalloc(0x28u); /*0x1b8607*/
    if ( !self->pausePort )
    {
      v5 = task_self(); /*0x1b861d*/
      if ( port_allocate_EXTERNAL(v5) )
      {
        IOLog("Audio: stream control thread port_allocate: %s\n");
        IOLog("Audio Driver error"); /*0x1b8643*/
      }
      if ( !dword_1E53A8 ) /*0x1b8652*/
      {
        v6 = +[Object alloc](aNxlock, sel_alloc); /*0x1b8669*/
        dword_1E53A8 = -[NXLock init](v6, sel_init); /*0x1b8677*/
      }
      objc_msgSend(dword_1E53A8, sel_lock); /*0x1b868d*/
      dword_1E53A4 = self->pausePort; /*0x1b8698*/
      v7 = current_task_EXTERNAL(); /*0x1b86a3*/
      kernel_thread(v7, (int)sub_1B9160, v17); /*0x1b86a9*/
    }
    qmemcpy(v4, &unk_1D5E6C, 0x28u); /*0x1b86be*/
    v4[4] = self->pausePort; /*0x1b86c5*/
    v4[7] = self; /*0x1b86cb*/
    v4[8] = 0; /*0x1b86d1*/
    p_resumeTime = &self->pauseTime; /*0x1b86d4*/
LABEL_32:
    v4[9] = p_resumeTime; /*0x1b8943*/
    msg_send(v4, 1, 1000); /*0x1b894e*/
    return self; /*0x1b8953*/
  }
  if ( a3 != 2 )
  {
    if ( a3 == 4 )
      -[AudioStream markAbortionsExclude:](self, sel_markAbortionsExclude_, 1); /*0x1b8995*/
    else
      IOLog("audio: unrecognized stream control %d\n");
    return self; /*0x1b85d3*/
  }
  if ( a4 )
  {
    self->abortTime = a4; /*0x1b8857*/
    v4 = (_DWORD *)IOMalloc(0x28u); /*0x1b8873*/
    if ( !self->abortPort )
    {
      v13 = task_self(); /*0x1b8889*/
      if ( port_allocate_EXTERNAL(v13) )
      {
        IOLog("Audio: stream control thread port_allocate: %s\n");
        IOLog("Audio Driver error"); /*0x1b88af*/
      }
      if ( !dword_1E53A8 ) /*0x1b88be*/
      {
        v14 = +[Object alloc](aNxlock, sel_alloc); /*0x1b88d5*/
        dword_1E53A8 = -[NXLock init](v14, sel_init); /*0x1b88e3*/
      }
      objc_msgSend(dword_1E53A8, sel_lock); /*0x1b88f9*/
      dword_1E53A4 = self->abortPort; /*0x1b8904*/
      v15 = current_task_EXTERNAL(); /*0x1b890f*/
      kernel_thread(v15, (int)sub_1B9160, v19); /*0x1b8915*/
    }
    qmemcpy(v4, &unk_1D5E6C, 0x28u); /*0x1b892a*/
    v4[4] = self->abortPort; /*0x1b8931*/
    v4[7] = self; /*0x1b8937*/
    v4[8] = 2; /*0x1b893d*/
    p_resumeTime = &self->abortTime; /*0x1b8940*/
    goto LABEL_32; /*0x1b8940*/
  }
  if ( !-[AudioStream markAbortionsExclude:](self, sel_markAbortionsExclude_, 0) ) /*0x1b8965*/
    -[AudioStream sendControlMessage:mask:](self, sel_sendControlMessage_mask_, 4, 16); /*0x1b8980*/
  return self; /*0x1b89b0*/
}
