========================================================================
    APPLICATION : KnapsackProblem Overview
========================================================================
! BoundKnapsackSolver non-recursive version not yet finished - use "r" command argument (described bellow) !

HOW TO RUN PROGRAM: KnapsackProblem.exe file_name [solve_method] [r] [precision]
where [solve_method] is optional parameter for chosen method, can be: "brute", "heuristic", "bound", "fptas" or "dynamic" (without "")
[r] is optional parameter for brute and bound methods, making the traversing of state-space recursive. Otherwise queue + cycle is used
[precision] is optional parameter for FPTAS method - gives the required precision of result. When 0 used, the computation is equivalent with dynamic method. "Precision" is casted to (double) and should be between 0 and 1

At the moment when non-recursive B&B method used, the returned result vector isn't correct, although the result (price) itself is. Safe to use when storing used items is not needed. 

/////////////////////////////////////////////////////////////////////////////

EXAMPLE USAGE: 	KnapsackProblem ../data1/knap_4.inst.dat fptas 0.3
		KnapsackProblem ../data1/knap_10.inst.dat bound r

/////////////////////////////////////////////////////////////////////////////
