"""
System Design & Algorithms: Fraud Ring Detection

You are tasked with building a system to identify "rings of fraud"—groups of customers who are collectively running payment scams. The problem is divided into three sequential parts. Each part builds upon the logic of the previous one.

### Part 1: Single-Attribute Linking
Identify distinct groups of customers operating as a fraud ring. Customers belong to the same fraud ring if they share a common device ID.

Input: Array of strings formatted as `CustomerID:DeviceID`.
Example Input: transactions = ["A:d1", "B:d2", "C:d3", "D:d2", "B:d3"]
Expected Output: [{"B", "C", "D"}, {"A"}]

### Part 2: Multi-Attribute Linking
Customers are considered part of the same fraud ring if they share EITHER a Device ID OR a Credit Card ID. Determine the size of the largest single fraud ring.

Input: Array of strings formatted as `CustomerID:DeviceID:CreditCardID`.
Example Input: transactions = ["A:d1:123", "B:d2:456", "C:d3:123", "D:d2:789", "E:d2:999"]
Expected Output: 3

### Part 3: Risk Factor Calculation
Calculate the overall risk factor for each identified fraud ring (using Part 2 logic). The risk factor is the average of the valid members' scores. If any customer has a risk factor of exactly 0, they are considered a false positive and must be removed before calculating the group's average.

Input: Array of strings formatted as `CustomerID:DeviceID:CreditCardID:RiskFactor`.
Example Input: transactions = ["A:d1:123:90", "B:d2:456:50", "C:d3:123:0", "D:d2:789:100", "E:d2:999:30"]
Expected Output: [90.0, 60.0]
"""

from typing import List, Set

class FraudRingDetector:
    def identify_rings(self, transactions: List[str]) -> List[Set[str]]:
        """
        Part 1: Identify groups of customers linked by Device ID.
        """
        # TODO: Implement Part 1
        pass

    def largest_ring_size(self, transactions: List[str]) -> int:
        """
        Part 2: Return the size of the largest fraud ring linked by Device ID or Credit Card ID.
        """
        # TODO: Implement Part 2
        pass

    def calculate_risk_factors(self, transactions: List[str]) -> List[float]:
        """
        Part 3: Return the calculated risk factor for each valid fraud ring.
        """
        # TODO: Implement Part 3
        pass

# --- Test Cases ---
if __name__ == "__main__":
    detector = FraudRingDetector()

    print("--- Running Test Cases ---")

    # Part 1 Test
    part1_tx = ["A:d1", "B:d2", "C:d3", "D:d2", "B:d3"]
    # Expected: [{'B', 'C', 'D'}, {'A'}]
    print(f"Part 1 Output: {detector.identify_rings(part1_tx)}")

    # Part 2 Test
    part2_tx = ["A:d1:123", "B:d2:456", "C:d3:123", "D:d2:789", "E:d2:999"]
    # Expected: 3
    print(f"Part 2 Output: {detector.largest_ring_size(part2_tx)}")

    # Part 3 Test
    part3_tx = ["A:d1:123:90", "B:d2:456:50", "C:d3:123:0", "D:d2:789:100", "E:d2:999:30"]
    # Expected: [90.0, 60.0]
    print(f"Part 3 Output: {detector.calculate_risk_factors(part3_tx)}")
