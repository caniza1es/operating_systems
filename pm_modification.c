static void adjust_task_priority(struct task_struct *task)
{
    if (task->ptrace_involved) {
  
        task->prio = MAX_RT_PRIO - 10; 
    } else {
   
        task->prio = NORMAL_PRIO;
    }
}

static struct task_struct *pick_next_task_fair(struct rq *rq, struct task_struct *prev)
{
    struct task_struct *next;

    list_for_each_entry(next, &rq->cfs_tasks, se->tasks) {
        adjust_task_priority(next);
    }


    next = pick_next_entity(rq, &rq->cfs, &rq->cfs.curr);
    return next;
}
