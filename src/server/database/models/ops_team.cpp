#include <std_include.hpp>

#include "ops_team.hpp"

namespace database::ops_team {
class table final : public table_interface {
public:
    void create(database_t &database) override {
        database.run_query("mgstpp.ops_team.create");
    }
};

GET_FIELD_C(ops_team, std::uint64_t,
            team_id); // The id of the team (possibly a
                      // mission_teams table primary_key?)
GET_FIELD_C(ops_team, std::uint64_t,
            armored); // Number of armored vehicles deployed
GET_FIELD_C(ops_team, std::uint64_t, battle_gear); // Is battle gear deployed
GET_FIELD_C(ops_team, std::uint64_t, car);         // Number of cars deployed
GET_FIELD_C(ops_team, std::uint64_t,
            combat_count); // Deployed Main Combat Unit Size
GET_FIELD_C(ops_team, std::uint64_t,
            combat_rank_bottom); // When a range of ranks (like S+ - S) this
                                 // is the lowest rank
GET_FIELD_C(ops_team, std::uint64_t,
            combat_rank_top); // The highest rank deployed (see Staff Ranks
                              // (take rank and add 1))
GET_FIELD_C(ops_team, std::uint64_t, dead_rate); // ????
GET_FIELD_C(ops_team, std::uint64_t,
            is_valid); // When value is 1, the mission is marked as
                       // currently active for the client
GET_FIELD_C(ops_team, std::uint64_t,
            mission_id); // Matches the op mission_id, leading credence to
                         // database relations, maybe
GET_FIELD_C(ops_team, std::uint64_t,
            seed); // Seems to be 0 regardless of if it's an
                   // active team or not, and doesn't match
GET_FIELD_C(ops_team, std::uint64_t,
            staff_power); // Total Fighting Ability for this
                          // team (How it calculates Success
GET_FIELD_C(ops_team, std::uint64_t,
            sub_count); // Deployed Supporting Unit Size
GET_FIELD_C(ops_team, std::uint64_t,
            sub_rank_bottom); // When a range of ranks (like S+ - S) this is
                              // the lowest rank deployed
GET_FIELD_C(ops_team, std::uint64_t,
            sub_rank_top); // The highest rank deployed (see Staff Ranks
                           // (take rank and add 1))
GET_FIELD_C(ops_team, std::uint64_t, tank);       // Number of tanks deployed
GET_FIELD_C(ops_team, std::uint64_t, team_power); // Seems to match staff_power
GET_FIELD_C(ops_team, std::uint64_t,
            time); // Time (in seconds) left of the mission
GET_FIELD_C(ops_team, std::uint64_t, truck); // Number of Trucks deployed
GET_FIELD_C(ops_team, std::uint64_t,
            walker_gear); // Number of walker gear deployed
GET_FIELD_C(ops_team, std::uint64_t,
            win_rate); // Unknown, doesn't match the missions win rate,
                       // maybe is their success level
GET_FIELD_C(ops_team, std::uint64_t, player_id);
} // namespace database::ops_team

REGISTER_TABLE(database::ops_team::table, -1)