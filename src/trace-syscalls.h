#ifndef TRACE_SYSCALLS_H
#define TRACE_SYSCALLS_H

/* Operating-system-specific operations. */
struct os_functions {
	/* <private> */
	gboolean (*initialize) (GtLoop *loop);
	status_t (*wait_for_first_process) (GtLoop *loop);
	gt_pid_t (*get_pid) (GtLoop *loop, vmi_event_t *event);
	gt_tid_t (*get_tid) (GtLoop *loop, vmi_event_t *event);
	char *(*get_process_name) (vmi_instance_t vmi, gt_pid_t pid);
	gboolean (*is_user_call) (GtLoop *loop, vmi_event_t *event);
};

/* Maximum number of VCPUs VisorFlow will support. */
#define _GT_MAX_VCPUS 16

/* Number of bits available for page offset. */
#define GT_PAGE_OFFSET_BITS 12

/* Default page size on our domain. */
#define GT_PAGE_SIZE (1 << GT_PAGE_OFFSET_BITS)

/* Intel breakpoint interrupt (INT 3) instruction. */
extern uint8_t GT_BREAKPOINT_INST;

#endif
