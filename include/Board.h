#include <array>
#include <iostream>
#include <ostream>
#include <string>

class Board {
public:
    /**
    * @brief Construct a new Board object
    * @remark This will set all grid to 0
    */
    Board();

    /**
     * @brief result of check input, for the sake of readability
     * 
     */
    enum PlacementResult {
        VALID_PLACEMENT,
        ALREADY_OCCUPIED,
        OUT_OF_RANGE,
        NEGATIVE_NUM,
        NUMBER_ONLY,
        NO_INPUT
    };

    /**
     * @brief game status, for the sake of readability
     * 
     */
    enum EndGameStat {
        CONTINUE,
        P1,
        P2,
        TIE
    };

    /**
     * @brief Check victory on each turn
     * 
     * @return EndGameStat current game status
     */
    EndGameStat checkVictory() const;

    /**
     * @brief place a piece on the board
     * 
     * @param x x location
     * @param y y locatiohn
     * @param player which player is playing
     * @return PlacementResult whether the placement is success or not
     * @remark This function will modify data if the coordinate is valid, won't otherwise
     */
    PlacementResult play(int x, int y, int player);

    /**
     * @brief toString
     * 
     * @return std::string 
     */
    operator std::string() const;
    
    /**
     * @brief << operator
     * 
     * @param os 
     * @param other 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Board& other);

    /**
     * @brief Get the Placement Msg corresponding to given result
     * 
     * @param res placement result
     * @return std::string string
     */
    static std::string getPlacementMsg(PlacementResult res);

private:
    int played = 0;

    int data[3][3];

    static constexpr std::array<const char*, 5> placement_msg = {
        "Placement OK",
        "This place is already occupied",
        "The coordinate is out of the board",
        "The coordinate is negative",
        "Please only input number"
    };

    static constexpr const char* board_template = "+---+---+---+\n| k | k | k |\n+---+---+---+\n| k | k | k |\n+---+---+---+\n| k | k | k |\n+---+---+---+\n";

    /**
     * @brief validate the coordinate is valid or not
     * 
     * @param x x coord
     * @param y y coord
     * @return PlacementResult result of the validation, 0 is OK
     */
    PlacementResult validatePlacement(int x, int y) const;
};
