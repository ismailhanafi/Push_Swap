#include "push_swap.h"

t_bench	*bench_get(void)
{
	static t_bench	bench;

	return (&bench);
}

void	benchmark_init(int *a, int n, t_strategy requested)
{
	t_bench	*bench;

	bench = bench_get();
	bench->disorder = disorder(a, n);
	bench->requested = requested;
	bench->strategy = requested;
	if (requested == str_adaptive)
	{
		if (bench->disorder < 0.2)
			bench->strategy = str_simple;
		else if (bench->disorder < 0.5)
			bench->strategy = str_medium;
		else
			bench->strategy = str_complex;
	}
}

void	benchmark_record(t_operation op)
{
	t_bench	*bench;

	bench = bench_get();
	bench->operations[op]++;
	bench->total++;
}

static void	print_operation_count(const int *ops)
{
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ops[op_sa], ops[op_sb], ops[op_ss], ops[op_pa], ops[op_pb]);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ops[op_ra], ops[op_rb], ops[op_rr], ops[op_rra], ops[op_rrb],
		ops[op_rrr]);
}

void	benchmark_report(void)
{
	t_bench		*bench;
	int			pct;
	static char	*complexity[] = {"O(n^2)", "O(n * sqrt(n))",
		"O(n log n)"};
	static char	*names[] = {"Simple", "Medium", "Complex", "Adaptive"};

	bench = bench_get();
	pct = (int)(bench->disorder * 10000 + 0.5);
	ft_dprintf(2, "[bench] disorder: %d.", pct / 100);
	if (pct % 100 < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", pct % 100);
	ft_dprintf(2, "[bench] strategy: %s / %s\n",
		names[bench->requested], complexity[bench->strategy]);
	ft_dprintf(2, "[bench] total_ops: %d\n", bench->total);
	print_operation_count(bench->operations);
}
