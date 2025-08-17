# Combat Ops:

```json
{
    "mission_list": [
        {
            // An Array of Mission Objects
            "armored_max": 0, // Max number of armored vehicles allowed(?)
            "armored_min": 0, // Min number of armored vehicles required(?)
            "battle_gear": 0, // Is the battle gear required(?)
            "car_max": 0, // Max number of cars/jeeps allowed(?)
            "car_min": 0, // Min number of cars/jeeps required(?)
            "category": 7, // Seems to match name_key (Name Key comes from Category I guess?)(See Name Key)
            "combat_count": 10, // Required Main Combat Unit Size
            "combat_rank": 7, // Minimum Combat Unit Staff Rank (See Staff Ranks)
            "dead_rate": 25, // Base Predicted Losses (Modified by things like Fighting Ability, I guess)
            "is_campaign": 1, // Unsure what the difference is but visually if it's 1 it's gold and if it's 0 it's not(?)
            "latitude": -18300, // Latitude of Location on the map in the menu
            "longitude": 15500, // Longitude of Location on the map in the menu
            "max_dead_rate": 50, // Max Predicted Losses
            "min_dead_rate": 0, // Min Predicted Losses
            "max_win_rate": 95, // I don't know if these matter? it only seems to care about "win_rate" ????
            "min_win_rate": 40, // I don't know if these matter? it only seems to care about "win_rate" ????
            "mission_id": 101, // May just order the Missions in the list, as well as for referencing info in databases on the server
            "name_key": 7, // Mission Name in List (See Name Key)
            "primary_reward": [
                // List of objects
                {
                    "bottom_type": 2, // Just seems to match the type
                    "mecha_type": 0, // For some rewards seems to indicate a subcategory (Like the missiles) otherwise 0
                    "rate": 1000000, // Possibly Acquisition Probability
                    "section": 2, // Another subcategory indicator, may be staff only, is 0 for anything else
                    "type": 2, // See Reward Types
                    "value": 20 // How many/much of the reward you get (5 soldiers/20,000 GMP)
                }
            ],
            "reward": 2, // Reward type of the first primary reward
            "section": 2, // Supporting Member Section (usually from different staff section to combat, see Staff Sections)
            "section_count": 10, // Required Supporting Member Count
            "section_rank": 5, // Required Staff Rank of Section (See Staff Ranks)
            "seed": 28980, // Some kind of seed for the missions rng maybe, seed changes with every load, maybe only relevant when first deployed(?)
            "server_text_id": 0, // Unknown, always seems to be 0
            "tank_max": 0, // Max number of tanks allowed(?)
            "tank_max": 0, // Min number of tanks required(?)
            "team": {
                // Object With info on currently deployed team, zeroed out on first listing
                "armored": 0, // Number of armored vehicles deployed
                "battle_gear": 0, // Is battle gear deployed
                "car": 0, // Number of cars deployed
                "combat_count": 0, // Deployed Main Combat Unit Size
                "combat_rank_bottom": 0, // When a range of ranks (like S+ - S) this is the lowest rank deployed (see Staff Ranks (take rank and add 1))
                "combat_rank_top": 0, // The highest rank deployed (see Staff Ranks (take rank and add 1))
                "dead_rate": 0, // ????
                "is_valid": 0, // When value is 1, the mission is marked as currently active for the client
                "mission_id": 0, // Matches the op mission_id, leading credence to database relations, maybe team is pulled from an "active_ops" table?
                "seed": 0, // Seems to be 0 regardless of if it's an active team or not, and doesn't match the missions seed
                "staff_power": 0, // Total Fighting Ability for this team (How it calculates Success Probability and Predicted Losses?)
                "sub_count": 0, // Deployed Supporting Unit Size
                "sub_rank_bottom": 0, // When a range of ranks (like S+ - S) this is the lowest rank deployed (see Staff Ranks (take rank and add 1))
                "sub_rank_top": 0, // The highest rank deployed (see Staff Ranks (take rank and add 1))
                "tank": 0, // Number of tanks deployed
                "team_id": 0, // The id of the team (possibly a mission_teams table primary_key?)
                "team_power": 0, // Seems to match staff_power
                "time": 0, // Time (in seconds) left of the mission
                "truck": 0, // Number of Trucks deployed
                "walker_gear": 0, // Number of walker gear deployed
                "win_rate": 0 // Unknown, doesn't match the missions win rate, maybe is their success level once complete?
            },
            "time": 2500, // Time in minutes that the mission will take
            "time_random": 0, // Some kind of random time value, always seems to be 0(?)
            "truck_max": 0, // Max number of trucks allowed
            "truck_min": 0, // Min number of trucks required
            "walker_gear_max": 0, // Max number of walker gears allowed
            "walker_gear_min": 0, // Min number of walker gears required
            "win_rate": 95 // Max likelyhood of success or percentage of these missions succeeded(?) Seems to just follow this number?
        }
    ],
    "mission_num": 1 // Items in the "mission_list" array
}
```

Enemy Fighting Ability seems to be calculated based on a number of factors such as the Ranks of both Combat and Section staff, the vehicles that are brought along, and possibly other things, it's calculated client side weirdly enough.

## Staff Ranks (combat_rank and section_rank):

### Value corresponds to Rank

0. E
1. D
2. C
3. B
4. A
5. A+
6. A++
7. S
8. S+
9. S++

## Reward Types:

### Value corresponds to Reward

1. GMP
2. S++ Rank Staff
3. S+ Rank Staff
4. S Rank Staff
5. A++ Rank Staff
6. A+ Rank Staff
7. A Rank Staff
8. B Rank Staff
9. C Rank Staff
10. D Rank Staff
11. E Rank Staff
12. Common Metal
13. Minor Metal
14. Precious Metal
15. Fuel
16. Biological Material
17. Golden Crescent
18. African Peach
19. Digitalis (Purpurea)
20. Digitalis (Lutea)
21. Black Carrot
22. Wormwood
23. Tarragon
24. Haoma
25. Liquid Carbon Missiles (mecha_type 0)
26. Anti-Ballistic Missiles (mecha_type 1)

## Staff Sections:

### Value corresponds to Section

1. Combat
2. R&D
3. Base Development
4. Support
5. Intel
6. Medical

## Name Key:

### Value corresponds to Name

7. "Far Waters Exploitation"
8. "Reconstruction Support"
9. "Staff Recruitment"
10. "Staff Headhunting"
11. "Plants Gathering"
12. "Join Development: Liquid Carbon Missiles"
13. "Join Development: Anti-Ballistic Missiles"
