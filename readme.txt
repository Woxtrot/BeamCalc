Made by Wessel Eikelboom (S2565196) for the C++ assignment in the PiE course.
 Mechanical Engineering, Faculty of Engineering Technology, University of Twente

 This program is a simple beam calculator. It is made to handle simple bar, shaft and beam problems.

 What is beam theory?
 Beam theory considers the loading, deflection and stresses of a long one-dimensional structural member.
 This structural member can be connected (to the fixed world) and loaded in multiple different ways.
 Real-life problems can be simplified to represent a beam problem which can be analysed analytically.
 Structural members only considering longitudinal normal loading are considered to be bars.
 Members considering torsion/rotational loading around the longitudinal axis of the members are often considered to be shafts.
 Members considering bending due to transverse loading or applied transverse axis moments are considered to be beams.
 Combination of different load types is also possible but not considered in this calculator.
 Aspects such as deflection and stresses are dependent on geometric aspects such as length and cross-section, and material aspects
 such as shear and elastic modulus. For more information about beam theory: https://en.wikipedia.org/wiki/Euler%E2%80%93Bernoulli_beam_theory
 and : https://mechanicalc.com/reference/beam-analysis

 This calculator is set up to consider either a bar, shaft or beam problem.
 Some notes:
 Support
      Bars and shafts are only cantilever supported
      Beams can be cantilever or simply supported
 Loading
      All three problems types support point and distributed loading
      Beams also support moment loading
      Point loads and moments can be put anywhere on the member
      Distributed loads are uniform and span the entire member
 Cross-section
      Bars and beams consider circular, rectangular and I-beam cross-sections
      Shafts only consider circular cross-section

READ ME Important note:
	Only cantilever point and distributed load equations for beams (all cross-sections) are fully implemented as of 30-10-2023
	This is done as implementation of the actual calculations is repetitive and does not add significantly to this assignment.