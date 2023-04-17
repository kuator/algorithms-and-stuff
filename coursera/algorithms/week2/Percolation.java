/* *****************************************************************************
 *  Name:              Johanna Mesa Ramos
 *  Coursera User ID:  c02b4bb527298de170192d644483baeb
 *  Last modified:     06/07/2020
 *  Course: Algorithms, Part I https://www.coursera.org/learn/algorithms-part1
 **************************************************************************** */

import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private WeightedQuickUnionUF gridBackwash;
    private WeightedQuickUnionUF grid;
    private boolean[] nodeStates;
    private int n;
    private int top;
    private int bottom;
    private int openSites;

    /**
     * Creates n-by-n nodeStates, with all sites initially blocked
     * Creates n-by-n + 2 WeightedQuickUnionUF gridBackwash, the +2 is for virtual top/bottom nodes
     * Creates n-by-n + 1 WeightedQuickUnionUF grid, the +1 is for only the top virtual node and to
     * avoid backwash
     * in the method isFull
     *
     * @param n Dimension of the grid
     */
    public Percolation(int n) {
        if (n < 1)
            throw new java.lang.IllegalArgumentException(
                    "Stop right there, N must be greater than 0");

        this.n = n;
        top = get1DIndex(n, n) + 1;
        bottom = get1DIndex(n, n) + 2;
        openSites = 0;
        gridBackwash = new WeightedQuickUnionUF(n * n + 2);
        grid = new WeightedQuickUnionUF(n * n + 1); // Only add top virtual node
        nodeStates = new boolean[n * n];
    }

    /**
     * @param r row index, -1 because problem is 1 index based
     * @param c col index, -1 because problem is 1 index based
     * @return index from 2D array mapped to 1D array
     */
    private int get1DIndex(int r, int c) {
        r -= 1;
        c -= 1;
        return (r * n) + c;
    }

    private boolean outOfRange(int row, int col, boolean throwEx) {
        if (row < 1 || col < 1 || row > n || col > n) {
            if (throwEx)
                throw new java.lang.IllegalArgumentException("Values are out of range");

            return false;
        }
        return true;
    }

    public void open(int row, int col) {
        outOfRange(row, col, true);

        if (isOpen(row, col))
            return;

        int i = get1DIndex(row, col);
        nodeStates[i] = true;
        openSites += 1;

        if (row == 1) {
            gridBackwash.union(top, i);
            grid.union(top, i);
        }

        if (row == n)
            gridBackwash.union(bottom, i);

        union(row - 1, col, i);
        union(row, col + 1, i);
        union(row + 1, col, i);
        union(row, col - 1, i);
    }

    private void union(int r, int c, int to) {
        if (!outOfRange(r, c, false) || !isOpen(r, c))
            return;
        gridBackwash.union(get1DIndex(r, c), to);
        grid.union(get1DIndex(r, c), to);
    }

    public boolean isOpen(int row, int col) {
        outOfRange(row, col, true);
        return nodeStates[get1DIndex(row, col)];
    }

    /**
     * A full site is an open site that can be connected to an open site in the top row
     * via a chain of neighboring (left, right, up, down) open sites.
     *
     * @param row
     * @param col
     * @return boolean
     */
    public boolean isFull(int row, int col) {
        outOfRange(row, col, true);
        return isOpen(row, col) && grid.connected(get1DIndex(row, col), top);
    }

    public int numberOfOpenSites() {
        return openSites;
    }

    public boolean percolates() {
        return gridBackwash.connected(bottom, top);
    }

    public static void main(String[] args) {
    }
}
