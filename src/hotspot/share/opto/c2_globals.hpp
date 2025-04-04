/*
 * Copyright (c) 2000, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_OPTO_C2_GLOBALS_HPP
#define SHARE_VM_OPTO_C2_GLOBALS_HPP

#include "runtime/globals.hpp"
#include "utilities/macros.hpp"

#include CPU_HEADER(c2_globals)
#include OS_HEADER(c2_globals)

//
// Defines all globals flags used by the server compiler.
//

#define C2_FLAGS(develop, \
                 develop_pd, \
                 product, \
                 product_pd, \
                 diagnostic, \
                 diagnostic_pd, \
                 experimental, \
                 notproduct, \
                 range, \
                 constraint, \
                 writeable) \
                                                                            \
  diagnostic(bool, StressLCM, false,                                        \
          "Randomize instruction scheduling in LCM")                        \
                                                                            \
  diagnostic(bool, StressGCM, false,                                        \
          "Randomize instruction scheduling in GCM")                        \
                                                                            \
  develop(bool, StressMethodHandleLinkerInlining, false,                    \
          "Stress inlining through method handle linkers")                  \
                                                                            \
  develop(intx, OptoPrologueNops, 0,                                        \
          "Insert this many extra nop instructions "                        \
          "in the prologue of every nmethod")                               \
          range(0, 128)                                                     \
                                                                            \
  product_pd(intx, InteriorEntryAlignment,                                  \
          "Code alignment for interior entry points "                       \
          "in generated code (in bytes)")                                   \
          constraint(InteriorEntryAlignmentConstraintFunc, AfterErgo)       \
                                                                            \
  product(intx, MaxLoopPad, (OptoLoopAlignment-1),                          \
          "Align a loop if padding size in bytes is less or equal to this " \
          "value")                                                          \
          range(0, max_jint)                                                \
                                                                            \
  product(intx, MaxVectorSize, 64,                                          \
          "Max vector size in bytes, "                                      \
          "actual size could be less depending on elements type")           \
          range(0, max_jint)                                                \
                                                                            \
  product(bool, AlignVector, true,                                          \
          "Perform vector store/load alignment in loop")                    \
                                                                            \
  product(intx, NumberOfLoopInstrToAlign, 4,                                \
          "Number of first instructions in a loop to align")                \
          range(0, max_jint)                                                \
                                                                            \
  notproduct(intx, IndexSetWatch, 0,                                        \
          "Trace all operations on this IndexSet (-1 means all, 0 none)")   \
          range(-1, 0)                                                      \
                                                                            \
  develop(intx, OptoNodeListSize, 4,                                        \
          "Starting allocation size of Node_List data structures")          \
          range(0, max_jint)                                                \
                                                                            \
  develop(intx, OptoBlockListSize, 8,                                       \
          "Starting allocation size of Block_List data structures")         \
          range(0, max_jint)                                                \
                                                                            \
  develop(intx, OptoPeepholeAt, -1,                                         \
          "Apply peephole optimizations to this peephole rule")             \
                                                                            \
  notproduct(bool, PrintIdeal, false,                                       \
          "Print ideal graph before code generation")                       \
                                                                            \
  notproduct(bool, PrintOpto, false,                                        \
          "Print compiler2 attempts")                                       \
                                                                            \
  notproduct(bool, PrintOptoInlining, false,                                \
          "Print compiler2 inlining decisions")                             \
                                                                            \
  notproduct(bool, VerifyOpto, false,                                       \
          "Apply more time consuming verification during compilation")      \
                                                                            \
  notproduct(bool, VerifyIdealNodeCount, false,                             \
          "Verify that tracked dead ideal node count is accurate")          \
                                                                            \
  notproduct(bool, PrintIdealNodeCount, false,                              \
          "Print liveness counts of ideal nodes")                           \
                                                                            \
  notproduct(bool, VerifyOptoOopOffsets, false,                             \
          "Check types of base addresses in field references")              \
                                                                            \
  develop(bool, IdealizedNumerics, false,                                   \
          "Check performance difference allowing FP "                       \
          "associativity and commutativity...")                             \
                                                                            \
  diagnostic_pd(bool, IdealizeClearArrayNode,                               \
          "Replace ClearArrayNode by subgraph of basic operations.")        \
                                                                            \
  develop(bool, OptoBreakpoint, false,                                      \
          "insert breakpoint at method entry")                              \
                                                                            \
  notproduct(bool, OptoBreakpointOSR, false,                                \
          "insert breakpoint at osr method entry")                          \
                                                                            \
  notproduct(intx, BreakAtNode, 0,                                          \
          "Break at construction of this Node (either _idx or _debug_idx)") \
                                                                            \
  notproduct(bool, OptoBreakpointC2R, false,                                \
          "insert breakpoint at runtime stub entry")                        \
                                                                            \
  notproduct(bool, OptoNoExecute, false,                                    \
          "Attempt to parse and compile but do not execute generated code") \
                                                                            \
  notproduct(bool, PrintOptoStatistics, false,                              \
          "Print New compiler statistics")                                  \
                                                                            \
  diagnostic(bool, PrintOptoAssembly, false,                                \
          "Print New compiler assembly output")                             \
                                                                            \
  develop_pd(bool, OptoPeephole,                                            \
          "Apply peephole optimizations after register allocation")         \
                                                                            \
  develop(bool, OptoRemoveUseless, true,                                    \
          "Remove useless nodes after parsing")                             \
                                                                            \
  notproduct(bool, PrintFrameConverterAssembly, false,                      \
          "Print New compiler assembly output for frame converters")        \
                                                                            \
  notproduct(bool, PrintParseStatistics, false,                             \
          "Print nodes, transforms and new values made per bytecode parsed")\
                                                                            \
  notproduct(bool, PrintOptoPeephole, false,                                \
          "Print New compiler peephole replacements")                       \
                                                                            \
  develop(bool, PrintCFGBlockFreq, false,                                   \
          "Print CFG block freqencies")                                     \
                                                                            \
  develop(bool, TraceOptoParse, false,                                      \
          "Trace bytecode parse and control-flow merge")                    \
                                                                            \
  product_pd(intx,  LoopUnrollLimit,                                        \
          "Unroll loop bodies with node count less than this")              \
          range(0, max_jint / 4)                                            \
                                                                            \
  product_pd(intx, LoopPercentProfileLimit,                                 \
             "Unroll loop bodies with % node count of profile limit")       \
             range(10, 100)                                                 \
                                                                            \
  product(intx,  LoopMaxUnroll, 16,                                         \
          "Maximum number of unrolls for main loop")                        \
          range(0, max_jint)                                                \
                                                                            \
  product_pd(bool,  SuperWordLoopUnrollAnalysis,                            \
           "Map number of unrolls for main loop via "                       \
           "Superword Level Parallelism analysis")                          \
                                                                            \
  experimental(bool, PostLoopMultiversioning, false,                        \
           "Multi versioned post loops to eliminate range checks")          \
                                                                            \
  notproduct(bool, TraceSuperWordLoopUnrollAnalysis, false,                 \
          "Trace what Superword Level Parallelism analysis applies")        \
                                                                            \
  diagnostic(bool, UseVectorMacroLogic, true,                               \
          "Use ternary macro logic instructions")                           \
                                                                            \
  product(intx,  LoopUnrollMin, 4,                                          \
          "Minimum number of unroll loop bodies before checking progress"   \
          "of rounds of unroll,optimize,..")                                \
          range(0, max_jint)                                                \
                                                                            \
  product(bool, UseSubwordForMaxVector, true,                               \
          "Use Subword Analysis to set maximum vector size")                \
                                                                            \
  product(bool, UseVectorCmov, false,                                       \
          "Use Vectorized Cmov")                                            \
                                                                            \
  develop(intx, UnrollLimitForProfileCheck, 1,                              \
          "Don't use profile_trip_cnt() to restrict unrolling until "       \
          "unrolling would push the number of unrolled iterations above "   \
          "UnrollLimitForProfileCheck. A higher value allows more "         \
          "unrolling. Zero acts as a very large value." )                   \
          range(0, max_intx)                                                \
                                                                            \
  product(intx, MultiArrayExpandLimit, 6,                                   \
          "Maximum number of individual allocations in an inline-expanded " \
          "multianewarray instruction")                                     \
          range(0, max_jint)                                                \
                                                                            \
  notproduct(bool, TraceProfileTripCount, false,                            \
          "Trace profile loop trip count information")                      \
                                                                            \
  product(bool, UseCountedLoopSafepoints, false,                            \
          "Force counted loops to keep a safepoint")                        \
                                                                            \
  product(bool, UseLoopPredicate, true,                                     \
          "Generate a predicate to select fast/slow loop versions")         \
                                                                            \
  develop(bool, TraceLoopPredicate, false,                                  \
          "Trace generation of loop predicates")                            \
                                                                            \
  develop(bool, TraceLoopOpts, false,                                       \
          "Trace executed loop optimizations")                              \
                                                                            \
  develop(bool, TraceLoopLimitCheck, false,                                 \
          "Trace generation of loop limits checks")                         \
                                                                            \
  develop(bool, TraceRangeLimitCheck, false,                                \
          "Trace additional overflow checks in RCE")                        \
                                                                            \
  /* OptimizeFill not yet supported on PowerPC. */                          \
  product(bool, OptimizeFill, true PPC64_ONLY(&& false),                    \
          "convert fill/copy loops into intrinsic")                         \
                                                                            \
  develop(bool, TraceOptimizeFill, false,                                   \
          "print detailed information about fill conversion")               \
                                                                            \
  develop(bool, OptoCoalesce, true,                                         \
          "Use Conservative Copy Coalescing in the Register Allocator")     \
                                                                            \
  develop(bool, UseUniqueSubclasses, true,                                  \
          "Narrow an abstract reference to the unique concrete subclass")   \
                                                                            \
  develop(bool, UseExactTypes, true,                                        \
          "Use exact types to eliminate array store checks and v-calls")    \
                                                                            \
  product(intx, TrackedInitializationLimit, 50,                             \
          "When initializing fields, track up to this many words")          \
          range(0, 65535)                                                   \
                                                                            \
  product(bool, ReduceFieldZeroing, true,                                   \
          "When initializing fields, try to avoid needless zeroing")        \
                                                                            \
  product(bool, ReduceInitialCardMarks, true,                               \
          "When initializing fields, try to avoid needless card marks")     \
                                                                            \
  product(bool, ReduceBulkZeroing, true,                                    \
          "When bulk-initializing, try to avoid needless zeroing")          \
                                                                            \
  product(bool, UseFPUForSpilling, false,                                   \
          "Spill integer registers to FPU instead of stack when possible")  \
                                                                            \
  develop_pd(intx, RegisterCostAreaRatio,                                   \
          "Spill selection in reg allocator: scale area by (X/64K) before " \
          "adding cost")                                                    \
                                                                            \
  develop_pd(bool, UseCISCSpill,                                            \
          "Use ADLC supplied cisc instructions during allocation")          \
                                                                            \
  notproduct(bool, VerifyGraphEdges , false,                                \
          "Verify Bi-directional Edges")                                    \
                                                                            \
  notproduct(bool, VerifyDUIterators, true,                                 \
          "Verify the safety of all iterations of Bi-directional Edges")    \
                                                                            \
  notproduct(bool, VerifyHashTableKeys, true,                               \
          "Verify the immutability of keys in the VN hash tables")          \
                                                                            \
  notproduct(bool, VerifyRegisterAllocator , false,                         \
          "Verify Register Allocator")                                      \
                                                                            \
  develop_pd(intx, FLOATPRESSURE,                                           \
          "Number of float LRG's that constitute high register pressure")   \
          range(0, max_jint)                                                \
                                                                            \
  develop_pd(intx, INTPRESSURE,                                             \
          "Number of integer LRG's that constitute high register pressure") \
          range(0, max_jint)                                                \
                                                                            \
  notproduct(bool, TraceOptoPipelining, false,                              \
          "Trace pipelining information")                                   \
                                                                            \
  notproduct(bool, TraceOptoOutput, false,                                  \
          "Trace pipelining information")                                   \
                                                                            \
  product_pd(bool, OptoScheduling,                                          \
          "Instruction Scheduling after register allocation")               \
                                                                            \
  product_pd(bool, OptoRegScheduling,                                       \
          "Instruction Scheduling before register allocation for pressure") \
                                                                            \
  product(bool, PartialPeelLoop, true,                                      \
          "Partial peel (rotate) loops")                                    \
                                                                            \
  product(intx, PartialPeelNewPhiDelta, 0,                                  \
          "Additional phis that can be created by partial peeling")         \
          range(0, max_jint)                                                \
                                                                            \
  notproduct(bool, TracePartialPeeling, false,                              \
          "Trace partial peeling (loop rotation) information")              \
                                                                            \
  product(bool, PartialPeelAtUnsignedTests, true,                           \
          "Partial peel at unsigned tests if no signed test exists")        \
                                                                            \
  product(bool, ReassociateInvariants, true,                                \
          "Enable reassociation of expressions with loop invariants.")      \
                                                                            \
  product(bool, LoopUnswitching, true,                                      \
          "Enable loop unswitching (a form of invariant test hoisting)")    \
                                                                            \
  notproduct(bool, TraceLoopUnswitching, false,                             \
          "Trace loop unswitching")                                         \
                                                                            \
  product(bool, AllowVectorizeOnDemand, true,                               \
          "Globally supress vectorization set in VectorizeMethod")          \
                                                                            \
  product(bool, UseSuperWord, true,                                         \
          "Transform scalar operations into superword operations")          \
                                                                            \
  develop(bool, SuperWordRTDepCheck, false,                                 \
          "Enable runtime dependency checks.")                              \
                                                                            \
  product(bool, SuperWordReductions, true,                                  \
          "Enable reductions support in superword.")                        \
                                                                            \
  product(bool, UseCMoveUnconditionally, false,                             \
          "Use CMove (scalar and vector) ignoring profitability test.")     \
                                                                            \
  product(bool, DoReserveCopyInSuperWord, true,                             \
          "Create reserve copy of graph in SuperWord.")                     \
                                                                            \
  notproduct(bool, TraceSuperWord, false,                                   \
          "Trace superword transforms")                                     \
                                                                            \
  notproduct(bool, TraceNewVectors, false,                                  \
          "Trace creation of Vector nodes")                                 \
                                                                            \
  diagnostic(bool, MergeStores, true,                                       \
          "Optimize stores by combining values into larger store")          \
                                                                            \
  develop(bool, TraceMergeStores, false,                                    \
          "Trace creation of merged stores")                                \
                                                                            \
  product_pd(bool, OptoBundling,                                            \
          "Generate nops to fill i-cache lines")                            \
                                                                            \
  product_pd(intx, ConditionalMoveLimit,                                    \
          "Limit of ops to make speculative when using CMOVE")              \
          range(0, max_jint)                                                \
                                                                            \
  /* Set BranchOnRegister == false. See 4965987. */                         \
  product(bool, BranchOnRegister, false,                                    \
          "Use Sparc V9 branch-on-register opcodes")                        \
                                                                            \
  develop(bool, SparcV9RegsHiBitsZero, true,                                \
          "Assume Sparc V9 I&L registers on V8+ systems are zero-extended") \
                                                                            \
  product(bool, UseRDPCForConstantTableBase, false,                         \
          "Use Sparc RDPC instruction for the constant table base.")        \
                                                                            \
  notproduct(bool, PrintIdealGraph, false,                                  \
          "Print ideal graph to XML file / network interface. "             \
          "By default attempts to connect to the visualizer on a socket.")  \
                                                                            \
  notproduct(intx, PrintIdealGraphLevel, 0,                                 \
          "Level of detail of the ideal graph printout. "                   \
          "System-wide value, -1=printing is disabled, "                    \
          "0=print nothing except IGVPrintLevel directives, "               \
          "4=all details printed. "                                         \
          "Level of detail of printouts can be set on a per-method level "  \
          "as well by using CompileCommand=option.")                        \
          range(-1, 4)                                                      \
                                                                            \
  notproduct(intx, PrintIdealGraphPort, 4444,                               \
          "Ideal graph printer to network port")                            \
          range(0, SHRT_MAX)                                                \
                                                                            \
  notproduct(ccstr, PrintIdealGraphAddress, "127.0.0.1",                    \
          "IP address to connect to visualizer")                            \
                                                                            \
  notproduct(ccstr, PrintIdealGraphFile, NULL,                              \
          "File to dump ideal graph to.  If set overrides the "             \
          "use of the network")                                             \
                                                                            \
  product(bool, UseBimorphicInlining, true,                                 \
          "Profiling based inlining for two receivers")                     \
                                                                            \
  product(bool, UseOnlyInlinedBimorphic, true,                              \
          "Don't use BimorphicInlining if can't inline a second method")    \
                                                                            \
  product(bool, InsertMemBarAfterArraycopy, true,                           \
          "Insert memory barrier after arraycopy call")                     \
                                                                            \
  develop(bool, SubsumeLoads, true,                                         \
          "Attempt to compile while subsuming loads into machine "          \
          "instructions.")                                                  \
                                                                            \
  develop(bool, StressRecompilation, false,                                 \
          "Recompile each compiled method without subsuming loads "         \
          "or escape analysis.")                                            \
                                                                            \
  develop(intx, ImplicitNullCheckThreshold, 3,                              \
          "Don't do implicit null checks if NPE's in a method exceeds "     \
          "limit")                                                          \
          range(0, max_jint)                                                \
                                                                            \
  product(intx, LoopOptsCount, 43,                                          \
          "Set level of loop optimization for tier 1 compiles")             \
          range(5, 43)                                                      \
                                                                            \
  /* controls for heat-based inlining */                                    \
                                                                            \
  develop(intx, NodeCountInliningCutoff, 18000,                             \
          "If parser node generation exceeds limit stop inlining")          \
          range(0, max_jint)                                                \
                                                                            \
  develop(intx, NodeCountInliningStep, 1000,                                \
          "Target size of warm calls inlined between optimization passes")  \
          range(0, max_jint)                                                \
                                                                            \
  develop(bool, InlineWarmCalls, false,                                     \
          "Use a heat-based priority queue to govern inlining")             \
                                                                            \
  /* Max values must not exceed WarmCallInfo::MAX_VALUE(). */               \
  develop(intx, HotCallCountThreshold, 999999,                              \
          "large numbers of calls (per method invocation) force hotness")   \
          range(0, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))      \
                                                                            \
  develop(intx, HotCallProfitThreshold, 999999,                             \
          "highly profitable inlining opportunities force hotness")         \
          range(0, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))      \
                                                                            \
  develop(intx, HotCallTrivialWork, -1,                                     \
          "trivial execution time (no larger than this) forces hotness")    \
          range(-1, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))     \
                                                                            \
  develop(intx, HotCallTrivialSize, -1,                                     \
          "trivial methods (no larger than this) force calls to be hot")    \
          range(-1, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))     \
                                                                            \
  develop(intx, WarmCallMinCount, -1,                                       \
          "number of calls (per method invocation) to enable inlining")     \
          range(-1, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))     \
                                                                            \
  develop(intx, WarmCallMinProfit, -1,                                      \
          "number of calls (per method invocation) to enable inlining")     \
          range(-1, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))     \
                                                                            \
  develop(intx, WarmCallMaxWork, 999999,                                    \
          "execution time of the largest inlinable method")                 \
          range(0, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))      \
                                                                            \
  develop(intx, WarmCallMaxSize, 999999,                                    \
          "size of the largest inlinable method")                           \
          range(0, ((intx)MIN2((int64_t)max_intx,(int64_t)(+1.0e10))))      \
                                                                            \
  product(intx, MaxNodeLimit, 80000,                                        \
          "Maximum number of nodes")                                        \
          range(1000, max_jint / 3)                                         \
                                                                            \
  product(intx, NodeLimitFudgeFactor, 2000,                                 \
          "Fudge Factor for certain optimizations")                         \
          constraint(NodeLimitFudgeFactorConstraintFunc, AfterErgo)         \
                                                                            \
  product(bool, UseJumpTables, true,                                        \
          "Use JumpTables instead of a binary search tree for switches")    \
                                                                            \
  product(bool, UseDivMod, true,                                            \
          "Use combined DivMod instruction if available")                   \
                                                                            \
  product_pd(intx, MinJumpTableSize,                                        \
          "Minimum number of targets in a generated jump table")            \
          range(0, max_intx)                                                \
                                                                            \
  product(intx, MaxJumpTableSize, 65000,                                    \
          "Maximum number of targets in a generated jump table")            \
          range(0, max_intx)                                                \
                                                                            \
  product(intx, MaxJumpTableSparseness, 5,                                  \
          "Maximum sparseness for jumptables")                              \
          range(0, max_intx / 4)                                            \
                                                                            \
  product(bool, EliminateLocks, true,                                       \
          "Coarsen locks when possible")                                    \
                                                                            \
  product(bool, EliminateNestedLocks, true,                                 \
          "Eliminate nested locks of the same object when possible")        \
                                                                            \
  notproduct(bool, PrintLockStatistics, false,                              \
          "Print precise statistics on the dynamic lock usage")             \
                                                                            \
  diagnostic(bool, PrintPreciseBiasedLockingStatistics, false,              \
          "Print per-lock-site statistics of biased locking in JVM")        \
                                                                            \
  diagnostic(bool, PrintPreciseRTMLockingStatistics, false,                 \
          "Print per-lock-site statistics of rtm locking in JVM")           \
                                                                            \
  notproduct(bool, PrintEliminateLocks, false,                              \
          "Print out when locks are eliminated")                            \
                                                                            \
  product(bool, EliminateAutoBox, true,                                     \
          "Control optimizations for autobox elimination")                  \
                                                                            \
  diagnostic(bool, UseImplicitStableValues, true,                           \
          "Mark well-known stable fields as such (e.g. String.value)")      \
                                                                            \
  product(intx, AutoBoxCacheMax, 128,                                       \
          "Sets max value cached by the java.lang.Integer autobox cache")   \
          range(0, max_jint)                                                \
                                                                            \
  experimental(bool, AggressiveUnboxing, false,                             \
          "Control optimizations for aggressive boxing elimination")        \
                                                                            \
  develop(bool, TracePostallocExpand, false, "Trace expanding nodes after"  \
          " register allocation.")                                          \
                                                                            \
  product(bool, DoEscapeAnalysis, true,                                     \
          "Perform escape analysis")                                        \
                                                                            \
  product(double, EscapeAnalysisTimeout, 20. DEBUG_ONLY(+40.),              \
          "Abort EA when it reaches time limit (in sec)")                   \
          range(0, DBL_MAX)                                                 \
                                                                            \
  develop(bool, ExitEscapeAnalysisOnTimeout, true,                          \
          "Exit or throw assert in EA when it reaches time limit")          \
                                                                            \
  notproduct(bool, PrintEscapeAnalysis, false,                              \
          "Print the results of escape analysis")                           \
                                                                            \
  product(bool, EliminateAllocations, true,                                 \
          "Use escape analysis to eliminate allocations")                   \
                                                                            \
  notproduct(bool, PrintEliminateAllocations, false,                        \
          "Print out when allocations are eliminated")                      \
                                                                            \
  product(intx, EliminateAllocationArraySizeLimit, 64,                      \
          "Array size (number of elements) limit for scalar replacement")   \
          range(0, max_jint)                                                \
                                                                            \
  product(bool, OptimizePtrCompare, true,                                   \
          "Use escape analysis to optimize pointers compare")               \
                                                                            \
  notproduct(bool, PrintOptimizePtrCompare, false,                          \
          "Print information about optimized pointers compare")             \
                                                                            \
  notproduct(bool, VerifyConnectionGraph , true,                            \
          "Verify Connection Graph construction in Escape Analysis")        \
                                                                            \
  product(bool, UseOptoBiasInlining, true,                                  \
          "Generate biased locking code in C2 ideal graph")                 \
                                                                            \
  product(bool, OptimizeStringConcat, true,                                 \
          "Optimize the construction of Strings by StringBuilder")          \
                                                                            \
  notproduct(bool, PrintOptimizeStringConcat, false,                        \
          "Print information about transformations performed on Strings")   \
                                                                            \
  product(intx, ValueSearchLimit, 1000,                                     \
          "Recursion limit in PhaseMacroExpand::value_from_mem_phi")        \
          range(0, max_jint)                                                \
                                                                            \
  product(intx, MaxLabelRootDepth, 1100,                                    \
          "Maximum times call Label_Root to prevent stack overflow")        \
          range(100, max_jint)                                              \
                                                                            \
  diagnostic(intx, DominatorSearchLimit, 1000,                              \
          "Iterations limit in Node::dominates")                            \
          range(0, max_jint)                                                \
                                                                            \
  product(bool, BlockLayoutByFrequency, true,                               \
          "Use edge frequencies to drive block ordering")                   \
                                                                            \
  product(intx, BlockLayoutMinDiamondPercentage, 20,                        \
          "Miniumum %% of a successor (predecessor) for which block "       \
          "layout a will allow a fork (join) in a single chain")            \
          range(0, 100)                                                     \
                                                                            \
  product(bool, BlockLayoutRotateLoops, true,                               \
          "Allow back branches to be fall throughs in the block layout")    \
                                                                            \
  diagnostic(bool, InlineReflectionGetCallerClass, true,                    \
          "inline sun.reflect.Reflection.getCallerClass(), known to be "    \
          "part of base library DLL")                                       \
                                                                            \
  diagnostic(bool, InlineObjectCopy, true,                                  \
          "inline Object.clone and Arrays.copyOf[Range] intrinsics")        \
                                                                            \
  diagnostic(bool, SpecialStringCompareTo, true,                            \
          "special version of string compareTo")                            \
                                                                            \
  diagnostic(bool, SpecialStringIndexOf, true,                              \
          "special version of string indexOf")                              \
                                                                            \
  diagnostic(bool, SpecialStringEquals, true,                               \
          "special version of string equals")                               \
                                                                            \
  diagnostic(bool, SpecialArraysEquals, true,                               \
          "special version of Arrays.equals(char[],char[])")                \
                                                                            \
  diagnostic(bool, SpecialEncodeISOArray, true,                             \
          "special version of ISO_8859_1$Encoder.encodeISOArray")           \
                                                                            \
  develop(bool, BailoutToInterpreterForThrows, false,                       \
          "Compiled methods which throws/catches exceptions will be "       \
          "deopt and intp.")                                                \
                                                                            \
  develop(bool, ConvertCmpD2CmpF, true,                                     \
          "Convert cmpD to cmpF when one input is constant in float range") \
                                                                            \
  develop(bool, ConvertFloat2IntClipping, true,                             \
          "Convert float2int clipping idiom to integer clipping")           \
                                                                            \
  develop(bool, Use24BitFPMode, true,                                       \
          "Set 24-bit FPU mode on a per-compile basis ")                    \
                                                                            \
  develop(bool, Use24BitFP, true,                                           \
          "use FP instructions that produce 24-bit precise results")        \
                                                                            \
  develop(bool, MonomorphicArrayCheck, true,                                \
          "Uncommon-trap array store checks that require full type check")  \
                                                                            \
  notproduct(bool, TracePhaseCCP, false,                                    \
          "Print progress during Conditional Constant Propagation")         \
                                                                            \
  develop(bool, PrintDominators, false,                                     \
          "Print out dominator trees for GVN")                              \
                                                                            \
  diagnostic(bool, TraceSpilling, false,                                    \
          "Trace spilling")                                                 \
                                                                            \
  diagnostic(bool, TraceTypeProfile, false,                                 \
          "Trace type profile")                                             \
                                                                            \
  develop(bool, PoisonOSREntry, true,                                       \
           "Detect abnormal calls to OSR code")                             \
                                                                            \
  develop(bool, SoftMatchFailure, trueInProduct,                            \
          "If the DFA fails to match a node, print a message and bail out") \
                                                                            \
  develop(bool, InlineAccessors, true,                                      \
          "inline accessor methods (get/set)")                              \
                                                                            \
  product(intx, TypeProfileMajorReceiverPercent, 90,                        \
          "% of major receiver type to all profiled receivers")             \
          range(0, 100)                                                     \
                                                                            \
  diagnostic(bool, PrintIntrinsics, false,                                  \
          "prints attempted and successful inlining of intrinsics")         \
                                                                            \
  develop(bool, StressReflectiveCode, false,                                \
          "Use inexact types at allocations, etc., to test reflection")     \
                                                                            \
  diagnostic(bool, DebugInlinedCalls, true,                                 \
         "If false, restricts profiled locations to the root method only")  \
                                                                            \
  notproduct(bool, VerifyLoopOptimizations, false,                          \
          "verify major loop optimizations")                                \
                                                                            \
  diagnostic(bool, ProfileDynamicTypes, true,                               \
          "do extra type profiling and use it more aggressively")           \
                                                                            \
  develop(bool, TraceIterativeGVN, false,                                   \
          "Print progress during Iterative Global Value Numbering")         \
                                                                            \
  develop(bool, VerifyIterativeGVN, false,                                  \
          "Verify Def-Use modifications during sparse Iterative Global "    \
          "Value Numbering")                                                \
                                                                            \
  notproduct(bool, TraceCISCSpill, false,                                   \
          "Trace allocators use of cisc spillable instructions")            \
                                                                            \
  product(bool, SplitIfBlocks, true,                                        \
          "Clone compares and control flow through merge points to fold "   \
          "some branches")                                                  \
                                                                            \
  develop(intx, FreqCountInvocations,  1,                                   \
          "Scaling factor for branch frequencies (deprecated)")             \
          range(1, max_intx)                                                \
                                                                            \
  product(intx, AliasLevel,     3,                                          \
          "0 for no aliasing, 1 for oop/field/static/array split, "         \
          "2 for class split, 3 for unique instances")                      \
          range(0, 3)                                                       \
          constraint(AliasLevelConstraintFunc,AfterErgo)                    \
                                                                            \
  develop(bool, VerifyAliases, false,                                       \
          "perform extra checks on the results of alias analysis")          \
                                                                            \
  product(bool, IncrementalInline, true,                                    \
          "do post parse inlining")                                         \
                                                                            \
  develop(bool, AlwaysIncrementalInline, false,                             \
          "do all inlining incrementally")                                  \
                                                                            \
  product(intx, LiveNodeCountInliningCutoff, 40000,                         \
          "max number of live nodes in a method")                           \
          range(0, max_juint / 8)                                           \
                                                                            \
  diagnostic(bool, OptimizeExpensiveOps, true,                              \
          "Find best control for expensive operations")                     \
                                                                            \
  diagnostic(bool, UseMathExactIntrinsics, true,                            \
          "Enables intrinsification of various java.lang.Math functions")   \
                                                                            \
  diagnostic(bool, UseCharacterCompareIntrinsics, false,                    \
          "Enables intrinsification of java.lang.Character functions")      \
                                                                            \
  diagnostic(bool, UseMultiplyToLenIntrinsic, false,                        \
          "Enables intrinsification of BigInteger.multiplyToLen()")         \
                                                                            \
  diagnostic(bool, UseSquareToLenIntrinsic, false,                          \
          "Enables intrinsification of BigInteger.squareToLen()")           \
                                                                            \
  diagnostic(bool, UseMulAddIntrinsic, false,                               \
          "Enables intrinsification of BigInteger.mulAdd()")                \
                                                                            \
  diagnostic(bool, UseMontgomeryMultiplyIntrinsic, false,                   \
          "Enables intrinsification of BigInteger.montgomeryMultiply()")    \
                                                                            \
  diagnostic(bool, UseMontgomerySquareIntrinsic, false,                     \
          "Enables intrinsification of BigInteger.montgomerySquare()")      \
                                                                            \
  experimental(bool, EnableVectorSupport, false,                            \
          "Enables VectorSupport intrinsics")                               \
                                                                            \
  experimental(bool, EnableVectorReboxing, false,                           \
          "Enables reboxing of vectors")                                    \
                                                                            \
  experimental(bool, EnableVectorAggressiveReboxing, false,                 \
          "Enables aggressive reboxing of vectors")                         \
                                                                            \
  product(bool, UseTypeSpeculation, true,                                   \
          "Speculatively propagate types from profiles")                    \
                                                                            \
  diagnostic(bool, UseInlineDepthForSpeculativeTypes, true,                 \
          "Carry inline depth of profile point with speculative type "      \
          "and give priority to profiling from lower inline depth")         \
                                                                            \
  product_pd(bool, TrapBasedRangeChecks,                                    \
          "Generate code for range checks that uses a cmp and trap "        \
          "instruction raising SIGTRAP. Used on PPC64.")                    \
                                                                            \
  product(intx, ArrayCopyLoadStoreMaxElem, 8,                               \
          "Maximum number of arraycopy elements inlined as a sequence of"   \
          "loads/stores")                                                   \
          range(0, max_intx)                                                \
                                                                            \
  develop(bool, StressArrayCopyMacroNode, false,                            \
          "Perform ArrayCopy load/store replacement during IGVN only")      \
                                                                            \
  develop(bool, RenumberLiveNodes, true,                                    \
          "Renumber live nodes")                                            \
                                                                            \
  product(uintx, LoopStripMiningIter, 0,                                    \
          "Number of iterations in strip mined loop")                       \
          range(0, max_juint)                                               \
                                                                            \
  product(uintx, LoopStripMiningIterShortLoop, 0,                           \
          "Loop with fewer iterations are not strip mined")                 \
          range(0, max_juint)                                               \
                                                                            \
  product(bool, UseProfiledLoopPredicate, true,                             \
          "move predicates out of loops based on profiling data")           \
                                                                            \
  diagnostic(bool, InlineSecondarySupersTest, true,                \
          "Inline the secondary supers hash lookup.")                       \

C2_FLAGS(DECLARE_DEVELOPER_FLAG, \
         DECLARE_PD_DEVELOPER_FLAG, \
         DECLARE_PRODUCT_FLAG, \
         DECLARE_PD_PRODUCT_FLAG, \
         DECLARE_DIAGNOSTIC_FLAG, \
         DECLARE_PD_DIAGNOSTIC_FLAG, \
         DECLARE_EXPERIMENTAL_FLAG, \
         DECLARE_NOTPRODUCT_FLAG, \
         IGNORE_RANGE, \
         IGNORE_CONSTRAINT, \
         IGNORE_WRITEABLE)

#endif // SHARE_VM_OPTO_C2_GLOBALS_HPP
