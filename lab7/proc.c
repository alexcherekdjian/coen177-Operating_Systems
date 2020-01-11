/*===========================================================================*
 *				pick_proc				     * 
 *===========================================================================*/
PRIVATE struct proc * pick_proc(void)
{
/* Decide who to run now.  A new process is selected an returned.
 * When a billable process is selected, record it in 'bill_ptr', so that the 
 * clock task can tell who to bill for system time.
 */
  register struct proc *rp;			/* process to run */
  int q;				/* iterate over queues */

  /* Check each of the scheduling queues for ready processes. The number of
   * queues is defined in proc.h, and priorities are set in the task table.
   * The lowest queue contains IDLE, which is always ready.
   */
   
 for (q=0; q < NR_SCHED_QUEUES; q++) {	
 	
 	int n = rand() % 10;
 	
 	if (q < 15 && n < 4){
 		q++;
 	} 
 	
	if(!(rp = rdy_head[q])) {
		TRACE(VF_PICKPROC, printf("queue %d empty\n", q););
		continue;
	}

#if DEBUG_RACE
	rp = random_process(rdy_head[q]);
#endif

	TRACE(VF_PICKPROC, printf("found %s / %d on queue %d\n", 
		rp->p_name, rp->p_endpoint, q););
	assert(proc_is_runnable(rp));
	if (priv(rp)->s_flags & BILLABLE)	 	
		bill_ptr = rp;		/* bill for system time */
	return rp;
  }
  return NULL;
}

